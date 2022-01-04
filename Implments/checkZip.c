#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALID_ZIP_SIGNATURE 0x04034b50
#define CENTRAL_DIRECTORY_EOCD 0x06054b50 //signature
#define CENTRAL_DIRECTORY_ENTRY_SIGNATURE 0x02014b50

typedef unsigned char UINT8;

/*
Offset	Bytes	Description[31]
0	4	Local file header signature = 0x04034b50 (PK?? or "PK\3\4")
4	2	Version needed to extract (minimum)
6	2	General purpose bit flag
8	2	Compression method; e.g. none = 0, DEFLATE = 8 (or "\0x08\0x00")
10	2	File last modification time
12	2	File last modification date
14	4	CRC-32 of uncompressed data
18	4	Compressed size (or 0xffffffff for ZIP64)
22	4	Uncompressed size (or 0xffffffff for ZIP64)
26	2	File name length (n)
28	2	Extra field length (m)
30	n	File name
30+n	m	Extra field
*/

typedef struct
{
	UINT8 signature[4];
	UINT8 version[2];
	UINT8 generalflag[2];
	UINT8 compressionMethod[2];
	UINT8 fileLastModTime[2];
	UINT8 fileLastModDate[2];
	UINT8 crc32[4];
	UINT8 compressedSize[4];
	UINT8 uncompressedSize[4];
	UINT8 filenameLength[2];
	UINT8 extrafieldLength[2];
	//char *fileName;
	//void *extraField;
}ZIP_LOCAL_HEADER_S;

typedef struct
{
	UINT8 signature[4];
	UINT8 version_madeby[2];
	UINT8 version_extract[2];
	UINT8 generalflag[2];
	UINT8 compressionMethod[2];
	UINT8 fileLastModTime[2];
	UINT8 fileLastModDate[2];
	UINT8 crc32[4];
	UINT8 compressedSize[4];
	UINT8 uncompressedSize[4];
	UINT8 filenameLength[2];
	UINT8 extrafieldLength[2];
	UINT8 fileCommentLength[2];
	UINT8 diskNumFileStarts[2];
	UINT8 internalFileAttribute[2];
	UINT8 externalFileAttribute[4];
	UINT8 relativeOffsetOfLocalHeader[4];
	//char *fileName;
	//void *extraField;
}ZIP_CENTRAL_HEADER_S;


typedef struct {
    unsigned int signature : 32;
    unsigned int number_of_disk : 16;
    unsigned int disk_where_cd_starts : 16;
    unsigned int number_of_cd_records : 16;
    unsigned int total_number_of_cd_records : 16;
    unsigned int size_of_cd : 32;
    unsigned int offset_of_start : 32;
    unsigned int comment_length : 16;
} ZipEOCD;


void dumpHeaderInfo(ZIP_LOCAL_HEADER_S *__header)
{
	
}

int main(void)
{
	FILE *pFile = fopen("fw.zip", "r");
	
	if (pFile == NULL) return -1;

    int fileSignature = 0;
    //Seek to start and read zip header
    fread(&fileSignature, sizeof(int), 1, pFile);
    if (fileSignature != VALID_ZIP_SIGNATURE) return -1;

    //Grab the file size
    long fileSize = 0;
    long currPos = 0;

    fseek(pFile, 0L, SEEK_END);
    fileSize = ftell(pFile);
    fseek(pFile, 0L, SEEK_SET);
    printf("zip->fileSize:%lu\n", fileSize);

    //Step back the size of the ZipEOCD 
    //If it doesn't have any comments, should get an instant signature match
    currPos = fileSize;
    int signature = 0;
    while (currPos > 0)
    {
        fseek(pFile, currPos, SEEK_SET);
        fread(&signature, sizeof(int), 1, pFile);
        if (signature == CENTRAL_DIRECTORY_EOCD)
        {
            break;
        }
        currPos -= sizeof(char); //step back one byte
    }

    if (currPos != 0)
    {
        ZipEOCD zipOECD;

        fseek(pFile, currPos, SEEK_SET);
        fread(&zipOECD, sizeof(ZipEOCD), 1, pFile);

        printf("zipOECD->signature:%d\n", zipOECD.signature);
        printf("zipOECD->number_of_disk:%u\n", zipOECD.number_of_disk);
        printf("zipOECD->disk_where_cd_starts:%u\n", zipOECD.disk_where_cd_starts);
        printf("zipOECD->number_of_cd_records:%u\n", zipOECD.number_of_cd_records);
        printf("zipOECD->total_number_of_cd_records:%u\n", zipOECD.total_number_of_cd_records);
        printf("zipOECD->size_of_cd:%u\n", zipOECD.size_of_cd);
        printf("zipOECD->offset_of_start:%u\n", zipOECD.offset_of_start);

        long memBlockSize = fileSize - zipOECD.offset_of_start;
        char *pData = (char*)malloc(memBlockSize + 1);
        long currMemBlockPos = 0;
        long currNullTerminatorPos = -1;

        if (pData)
        {
            memset(pData, 0, memBlockSize + 1);

            //Read in the whole central directory (also includes the ZipEOCD...)
            fseek(pFile, zipOECD.offset_of_start, SEEK_SET);
            fread((void*)pData, memBlockSize, 1, pFile);

            while (currMemBlockPos < memBlockSize)
            {
                int sig = 0;
                memcpy(&sig, pData + currMemBlockPos, 4);
                if (sig != CENTRAL_DIRECTORY_ENTRY_SIGNATURE)
                {
                    if (sig == CENTRAL_DIRECTORY_EOCD) {
                        //printf("!!! central dir eocd reached !!!\n");
                        return -1;
                    }

                    return -1; //something went wrong
                }
                //printf("%s:%d currMemBlockPos:%ld memBlockSize:%ld\n", __func__, __LINE__, currMemBlockPos, memBlockSize);

                if (currNullTerminatorPos > 0)
                {
                    *(pData+currNullTerminatorPos) = '\0';
                    currNullTerminatorPos = -1;
                }

                const long offsToFilenameLen = 28;
                const long offsToFieldLen = 30;
                const long offsetToFilename = 46;

                int filenameLength = 0;
                memcpy(&filenameLength, pData + currMemBlockPos + offsToFilenameLen, 2);

                int extraFieldLen = 0;
                memcpy(&extraFieldLen, pData + currMemBlockPos + offsToFieldLen, 2);

                const char *pFilepath = pData + currMemBlockPos + offsetToFilename;
                currNullTerminatorPos = (currMemBlockPos + offsetToFilename) + filenameLength;
                //pArchive->m_Entries.push_back(pFilepath);
                printf("pFilepath:%s\n", pFilepath);
                //printf("%s:%d currMemBlockPos:%ld extraFieldLen:%d\n", __func__, __LINE__, currMemBlockPos, extraFieldLen);
                //printf("%s:%d currMemBlockPos:%ld filenameLength:%d\n", __func__, __LINE__, currMemBlockPos, filenameLength);

                currMemBlockPos += (offsetToFilename + filenameLength + extraFieldLen);
                //printf("%s:%d currMemBlockPos:%ld memBlockSize:%ld\n", __func__, __LINE__, currMemBlockPos, memBlockSize);
            }

            free(pData);
        }

    }

	fclose(pFile);

	return 0;
}





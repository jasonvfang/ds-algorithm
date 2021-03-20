#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode ListHead_1;
struct ListNode ListHead_2;


int ListNode_init(struct ListNode *Head, int listNum, int len)
{
    int i = 0, j = 0;
    struct ListNode *last = Head;
    srand((unsigned)time(NULL));

    for(i = 0; i < len; i ++)
    {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));

        tmp->next = NULL;
        last->next = tmp;
        
        tmp->val = rand() % 100;

        last = tmp;
    }

    return 0;
}

void print_list(struct ListNode *ListHead)
{
    if(!ListHead)
    {
        return;
    }
    struct ListNode *p = ListHead->next;

    while(p)
    {
        printf("%d", p->val);
        p = p->next;
        if(p)
        {
            printf("-->");
        }
    }

    printf("\n");
}

void print_list_noheader(struct ListNode *list)
{
    if(!list)
    {
        return;
    }

    struct ListNode *p = list;

    while(p)
    {
        printf("%d", p->val);
        p = p->next;
        if(p)
        {
            printf("-->");
        }
    }

    printf("\n");
}


void do_insert(struct ListNode **head, struct ListNode *pCurr)
{
    //Find the right position to insert.
    struct ListNode *pTmp = *head;
    struct ListNode *pTmpPrev = *head;

    while (pTmp && pCurr->val > pTmp->val)
    {
        pTmpPrev = pTmp;
        pTmp = pTmp->next;
    }

    //head is greater than current.
    if (*head == pTmp)
    {
        pCurr->next = *head;
        *head = pCurr;
    }
    else
    {
        pTmpPrev->next = pCurr;
        pCurr->next = pTmp;
    }
}

struct ListNode* insertionSortList(struct ListNode* head)
{
    struct ListNode *pCurr = head;
    struct ListNode *newHeader = head;
    struct ListNode *pCurrNext = head;

    if (newHeader == NULL)
    {
        return NULL;
    }

    while (pCurr)
    {        
        if(pCurr->next && pCurr->next->val < pCurr->val)
        {
            struct ListNode *tmp = pCurr->next;
            pCurr->next = pCurr->next->next;

            //do insert
            do_insert(&newHeader, tmp);
        }
        else
        {
            pCurr = pCurr->next;
        }
    }

    return newHeader;
}

int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 5);

    printf("List:\n");
    print_list(&ListHead_1);

    struct ListNode *NewList = insertionSortList(ListHead_1.next);

    printf("New List:\n");
    print_list_noheader(NewList);

    return 0;
}


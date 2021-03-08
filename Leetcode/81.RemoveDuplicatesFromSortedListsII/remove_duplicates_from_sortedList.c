#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

    for(i = 0; i < len; i ++)
    {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));

        tmp->next = NULL;
        last->next = tmp;
        if (i >= 3 && i <= 5)
            tmp->val = 4;
        else
            tmp->val = i + 1;
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


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (head && k > 0)
    {
        struct ListNode* pTmp = head->next;
        struct ListNode* pPrev = head;
        struct ListNode* pheadAnchor = head;
        int length = 0;

        //Find the last node.
        while (pTmp)
        {
            length ++;
            if (NULL == pTmp->next)
            {
                length ++;
                break;
            }
           
            pPrev = pTmp;
            pTmp = pTmp->next;
        }

        if (pTmp == NULL && pPrev == pheadAnchor)
        {
            //only one node
            return head;
        }

        k = k % length;

        //Do rotate and starts with the last node.
        while (k --)
        {
            pTmp->next = pheadAnchor;
            pheadAnchor = pTmp;
            pPrev->next = NULL;

            struct ListNode* p = pheadAnchor;
            while (p)
            {
                if (p->next == pPrev)
                {
                    break;
                }

                p = p->next;
            }

            pTmp = pPrev;
            pPrev = p;
        }

        head = pheadAnchor;
    }

    return head;
}

struct ListNode* rotateRight2(struct ListNode* head, int k)
{
    if (head && k > 0)
    {
        struct ListNode* pTail = head;
        struct ListNode* pCurr = head;
        int length = 0, count = 0;

        //Find the last node.
        while (pTail)
        {
            if (NULL == pTail->next)
            {
                length ++;
                break;
            }

            length ++;
            pTail = pTail->next;
        }

        if (length == 1 || k == length)
        {
            return head;
        }

        k = k % length;
        count = length - (k + 1);

        while (count --)
        {
            pCurr = pCurr->next;
        }

        pTail->next = head;
        head = pCurr->next;
        pCurr->next = NULL;
    }

    return head;
}


int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 7);

    printf("List:\n");
    print_list(&ListHead_1);
    int k = atoi(argv[1]);

    struct ListNode *newList = rotateRight2(ListHead_1.next, k);

    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}

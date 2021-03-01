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

        if(tmp)
        {
            switch(i)
            {
               case 0:
                   if (listNum == 1)
                   {
                       tmp->val = 1;
                   }
                   else
                   {
                       tmp->val = 1;
                   }
                   break;
               case 1:
                   if (listNum == 1)
                   {
                       tmp->val = 2;
                   }
                   else
                   {
                       tmp->val = 3;
                   }
                  break;
               case 2:
                   if (listNum == 1)
                   {
                       tmp->val = 4;
                   }
                   else
                   {
                       tmp->val = 4;
                   }
                   break;
               case 3:
                   if (listNum == 1)
                   {
                       tmp->val = 5;
                   }
                   else
                   {
                       tmp->val = 5;
                   }
                   break;
                default:
                    break;
            }
            tmp->next = NULL;
            last->next = tmp;
            last = tmp;
        }
        else
        {
            return -1;
        }
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* p = head;
    struct ListNode* q = NULL;
    struct ListNode* pPrev = NULL;
    struct ListNode* retList = NULL;
    struct ListNode* tmpNext = NULL;

    while(p)
    {
        q = p->next;
        tmpNext = q;

        if (q == NULL)
        {
            if (retList == NULL)
                retList = p;
            
            break;
        }

        //backup next iterator
        tmpNext = q->next;

        //do swap.
        p->next = q->next;
        q->next = p;

        if (pPrev != NULL)
        {
            pPrev->next = q;
        }

        if (retList == NULL)
        {
            retList = q;
        }

        pPrev = p;
        p = tmpNext;
    }

    return retList;
}

int main()
{
    ListNode_init(&ListHead_1, 1, 1);

    printf("List:\n");
    print_list(&ListHead_1);

    struct ListNode *newList = swapPairs(ListHead_1.next);
    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}

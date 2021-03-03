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
        tmp->val = i + 1;
        tmp->next = NULL;
        last->next = tmp;
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

struct ListNode* reverseNodes(struct ListNode**head, struct ListNode**end)
{
    struct ListNode *retList = NULL;
    
    if (*head)
    {
        struct ListNode *pTmp = *head;

        while (pTmp)
        {
            struct ListNode *pNext = pTmp->next;

            if (retList == NULL)
            {
                retList = pTmp;
                pTmp->next = (*end)->next;
                *head = (*end)->next;
                pTmp = pNext;
                continue;
            }

            if (pTmp == (*end)){
                pTmp->next = retList;
                retList = pTmp;

                *end = (*head);

                break;
            }            

            pTmp->next = retList;
            retList = pTmp;

            //Next node
            pTmp = pNext;
        }
    }

    return retList;
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    int step = k - 1;
    struct ListNode *retList = NULL, *pStart = head , *ListTail = NULL;

    if (head == NULL || step <= 0)
        return head;

    struct ListNode *pEnd = pStart;
    struct ListNode *pTmp = pStart;

    while (pStart)
    {
        struct ListNode *pTmp = pStart;
        pEnd = pStart;
        step = k - 1;

        //Find the end node.
        while (pEnd)
        {
            if (step <= 0)
                break;

            pEnd = pEnd->next;
            step --;
        }

        if (pEnd == NULL){            
            break;//Skip this reverse.
        }

        //reverse from pStart to pEnd;
        if (retList == NULL){
            ListTail = pStart;//after reverse, start shoud be the end;
            retList = reverseNodes(&pStart, &pEnd);
        }
        else
        {
            ListTail->next = reverseNodes(&pStart, &pEnd);
            ListTail = pTmp; 
        }
    }

    return retList;
}


//recurse
int size(struct ListNode *head)
{
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

struct ListNode* reverseKGroupRecurse(struct ListNode* head, int k) 
{
    struct ListNode *curr=head,*later=NULL,*prev=NULL;
    int count=0;
    while(count!=k && curr)
    {
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
        count++;
    }
    if(curr)
    {
        if(size(curr)>=k)
        {
            head->next=reverseKGroupRecurse(curr,k);
        }
        else
        {
            head->next=curr;
        }
    }
    return prev;
}

int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 7);

    printf("List:\n");
    print_list(&ListHead_1);
    int k = atoi(argv[1]);

    struct ListNode *newList = reverseKGroupRecurse(ListHead_1.next, k);
    //struct ListNode *newList = reverseNodes(ListHead_1.next);
    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}

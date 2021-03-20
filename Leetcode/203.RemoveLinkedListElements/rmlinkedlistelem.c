#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    for(i = 0; i < len; i ++)
    {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));

        tmp->next = NULL;
        last->next = tmp;
        tmp->val = i + 1;

        if (i== 5){
            tmp->val = 8;
        }
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


struct ListNode* removeElements1(struct ListNode* head, int val)
{
    if (!head)
        return NULL;

    struct ListNode *curr = head, * pCurrPrev = NULL;
    struct ListNode dummyHead = {0, NULL};

    dummyHead.next = head;

    while (curr)
    {
        if (curr->val == val)
        {
            //remove head node
            if (curr == dummyHead.next)
            {
                dummyHead.next = curr->next;
                pCurrPrev = curr->next;
                free(curr);

                curr = dummyHead.next;
            }
            else
            {
                pCurrPrev->next = curr->next;
                free(curr);
                curr = pCurrPrev->next;
            }
        }
        else
        {
            pCurrPrev = curr;
            curr = curr->next;
        }
    }

    return dummyHead.next;
}


struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (!head)
        return NULL;

    struct ListNode *curr = head, *tail = NULL;
    struct ListNode dummyHead = {0, NULL};

    while (curr)
    {
        struct ListNode *pCurrNext = curr->next;

        if (curr->val == val)
        {
            free(curr);            
            curr = pCurrNext;

            continue;
        }

        //insert into new list
        if (dummyHead.next == NULL){
            dummyHead.next = curr;        
        }else{
            tail->next = curr;
        }

        tail = curr;
        tail->next = NULL;
        curr = pCurrNext;
    }

    return dummyHead.next;
}

int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 11);

    printf("List:\n");
    print_list(&ListHead_1);

    struct ListNode* newList = removeElements(ListHead_1.next, 1);

    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}


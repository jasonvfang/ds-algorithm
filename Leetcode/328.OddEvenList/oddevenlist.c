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

int isOdd(int val)
{
    return (val % 2 != 0);
}

struct ListNode* oddEvenList(struct ListNode* head)
{
    if (!head)
        return NULL;

    int idx = 1;
    struct ListNode dummyOddHead = {0, NULL};
    struct ListNode dummyEvenHead = {0, NULL};
    struct ListNode *oddTail = NULL, *evenTail = NULL, *next = NULL;

    while (head)
    {
        next = head->next;

        if (isOdd(idx))
        {
            if (dummyOddHead.next == NULL)
            {
                dummyOddHead.next = head;
            }
            else
            {
                oddTail->next = head;
            }

            oddTail = head;
            oddTail->next = NULL;
        }
        else
        {
            if (dummyEvenHead.next == NULL)
            {
                dummyEvenHead.next = head;
            }
            else
            {
                evenTail->next = head;
            }
            
            evenTail = head;
            evenTail->next = NULL;
        }

        head = next;
        idx ++;
    }

    //merge two list
    oddTail->next = dummyEvenHead.next;

    return dummyOddHead.next;
}


int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 5);

    printf("List:\n");
    print_list(&ListHead_1);

    struct ListNode *NewList = oddEvenList(ListHead_1.next);

    printf("New List:\n");
    print_list_noheader(NewList);

    return 0;
}


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

struct ListNode *reverseList(struct ListNode* head){
    struct ListNode *cur = head, *prev = NULL;
    while (cur){
        struct ListNode *prevNext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = prevNext;
    }
    return prev;
}

void reorderList(struct ListNode* head){
    struct ListNode *pMid = NULL, *pEnd = NULL, *pCurr = NULL;

    if (head == NULL || head->next == NULL)
        return ;

    pCurr = head;
    pEnd = head;
    pMid = head;

    //Find the middle
    while (pEnd->next && pEnd->next->next)
    {
        pEnd = pEnd->next->next;
        pMid = pMid->next;
    }

    pEnd = reverseList(pMid);

    while (pCurr){
        struct ListNode *prevCurNext = pCurr->next;
        struct ListNode *prevEndNext = pEnd->next;
        
        pCurr->next = pEnd;
        pEnd->next = prevCurNext;
        
        pEnd = prevEndNext;
        pCurr = prevCurNext;
    }
}


int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 5);

    printf("List:\n");
    print_list(&ListHead_1);

    reorderList(ListHead_1.next);

    printf("New List:\n");
    print_list_noheader(ListHead_1.next);

    return 0;
}


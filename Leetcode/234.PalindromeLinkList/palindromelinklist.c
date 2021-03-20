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

typedef int bool;

enum {
    false = 0,
    true
};

int ListNode_init(struct ListNode *Head, int listNum, int len)
{
    int i = 0, j = 0, c = len / 2;
    struct ListNode *last = Head;

    for(i = 0; i < len; i ++)
    {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));

        tmp->next = NULL;
        last->next = tmp;
        tmp->val = i + 1;

        if (i== 5)
        {
            tmp->val = 8;
        }
        else if (i >= 5)
        {
            tmp->val = c --;
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

struct ListNode *getMid(struct ListNode* head)
{
    struct ListNode *prev = head;
    struct ListNode *slow = head, *fast = head;

    while (fast && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    return slow;
}

bool isPalindrome(struct ListNode* head)
{
    if (head == NULL)
        return false;

    if (head->next == NULL)
        return true;

    struct ListNode *mid = getMid(head);
    struct ListNode *list2 = reverseList(mid);

    while (head && list2)
    {
        if (head->val != list2->val)
            return false;

        head = head->next;
        list2 = list2->next;
    }

    return true;
}


int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 11);

    printf("List:\n");
    print_list(&ListHead_1);

    printf("isPalindrome:%d\n", isPalindrome(ListHead_1.next));

    return 0;
}


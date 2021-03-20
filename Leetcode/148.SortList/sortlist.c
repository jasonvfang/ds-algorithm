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


struct ListNode* mergeList(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode dummyNode = {0, NULL};
    struct ListNode* ptr = &dummyNode;

    while (list1 && list2)
    {
        if (list1->val < list2->val) {
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }

    if (list1) 
        ptr->next = list1;
    else
        ptr->next = list2;

    return dummyNode.next;
}


struct ListNode* sortList(struct ListNode* head)
{
    if (!head || !head->next)
        return head;

    struct ListNode* mid = getMid(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);
    
    return mergeList(left, right);
}


int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 11);

    printf("List:\n");
    print_list(&ListHead_1);

    struct ListNode *NewList = sortList(ListHead_1.next);

    printf("New List:\n");
    print_list_noheader(NewList);

    return 0;
}


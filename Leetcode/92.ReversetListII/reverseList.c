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


struct ListNode* do_reverse(struct ListNode* head, struct ListNode* end)
{
    if (!head || !end){
        return NULL;
    }

    if (head == end)
        return head;

    struct ListNode pTmp = {0};
    while (head)
    {
        struct ListNode *pNext = head->next;

        if (pTmp.next == NULL){
            pTmp.next = head;
            head->next = end->next;
            head = pNext;
            continue;
        }

        head->next = pTmp.next;
        pTmp.next = head;

        head = pNext;

        if (pTmp.next == end || head == NULL)
            break;
    }

    return pTmp.next;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{    
    if (left > right)
        return NULL;//Invalid args.

    right -= left;

    struct ListNode dummyHead = {0};
    struct ListNode *pEnd = NULL, *pHeadPrev = head;
    dummyHead.next = head;

    while (head != NULL && --left)
    {
        pHeadPrev = head;
        head = head->next;
    }

    if (head == NULL)//Not found
    {
        return dummyHead.next;
    }

    pEnd = head;

    while (pEnd != NULL && right)
    {
        pEnd = pEnd->next;
        right --;
    }
    
    if (pEnd == NULL)//Not found
    {
        return dummyHead.next;
    }

    if (pHeadPrev == head)//head node
    {
        dummyHead.next = do_reverse(head, pEnd);
    }
    else
    {
        pHeadPrev->next = do_reverse(head, pEnd);
    }

    return dummyHead.next;
}


int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 5);

    printf("List:\n");
    print_list(&ListHead_1);

    struct ListNode *newList = reverseBetween(ListHead_1.next, 2, 4);

    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}

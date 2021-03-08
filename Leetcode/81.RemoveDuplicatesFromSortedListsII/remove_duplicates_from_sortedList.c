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
        if (i <= 2)
            tmp->val = 1;
        else if (i >= 3 && i <= 5)
            tmp->val = 4;
        else if (i >=8)
            tmp->val = 8;
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


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
    	return NULL;
    
	struct ListNode* p = NULL, *q = NULL, *pprev = NULL;
	
	p = head;
	q = p->next;
    pprev = p;

	while(p)
	{
        if (p && q && p->val == q->val)
        {
            struct ListNode*tmp = NULL;
            while (q && p->val == q->val)
            {
                tmp = q->next;                
                free(q);
                q = tmp;
            }
            
            if (p == pprev)//head node
            {
                pprev = tmp;
                head = pprev;
            }else{
                pprev->next = tmp;
            }
            
            free(p);
            p = tmp;
            
            if (p)
                q = p->next;
        }
        else
        {
            pprev = p;
            p = p->next;

            if (p == NULL || p->next == NULL)
                break;
           
            q = p->next;
        }
	}
	
	return head;
}

int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1,11);

    printf("List:\n");
    print_list(&ListHead_1);

    struct ListNode *newList = deleteDuplicates(ListHead_1.next);

    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}

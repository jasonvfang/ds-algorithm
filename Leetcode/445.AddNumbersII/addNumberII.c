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
                       tmp->val = 4;
                   }
                   else
                   {
                       tmp->val = 6;
                   }
                   break;
               case 1:
                   if (listNum == 1)
                   {
                       tmp->val = 7;
                   }
                   else
                   {
                       tmp->val = 9;
                   }
                  break;
               case 2:
                   if (listNum == 1)
                   {
                       tmp->val = 5;
                   }
                   else
                   {
                       tmp->val = 2;
                   }
                   
               case 3:
                   if (listNum == 1)
                   {
                       tmp->val = 6;
                   }
                   else
                   {
                       tmp->val = 4;
                   }
                  break;
               case 4:
                   if (listNum == 1)
                   {
                       tmp->val = 3;
                   }
                   else
                   {
                       tmp->val = 7;
                   }  
                   break;
               case 5:
                   if (listNum == 1)
                   {
                       tmp->val = 3;
                   }
                   else
                   {
                       tmp->val = 7;
                   }  
                   break;
               case 6:
                   if (listNum == 1)
                   {
                       tmp->val = 4;
                   }
                   else
                   {
                       tmp->val = 5;
                   }  
                   break;
               case 7:
                   if (listNum == 1)
                   {
                       tmp->val = 4;
                   }
                   else
                   {
                       tmp->val = 8;
                   }  
                   break;
               case 8:
                   if (listNum == 1)
                   {
                       tmp->val = 7;
                   }
                   else
                   {
                       tmp->val = 6;
                   }  
                   break;
               case 9:
                   if (listNum == 1)
                   {
                       tmp->val = 7;
                   }
                   else
                   {
                       tmp->val = 1;
                   }  
                   break;
               case 10:
                   if (listNum == 1)
                   {
                       tmp->val = 7;
                   }
                   else
                   {
                       tmp->val = 1;
                   }  
                   break;
               case 11:
                   if (listNum == 1)
                   {
                       tmp->val = 7;
                   }
                   else
                   {
                       tmp->val = 1;
                   }  
                   break;

                   
               }
            
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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p1 = NULL, *m1 = NULL;
    struct ListNode *tmpNode = NULL;
    
    p1 = l1;
    m1 = l2;

    struct ListNode *retList = NULL;
    struct ListNode *lastNode = retList;
    
    int carry = 0, TotalSum = 0, tmpSum = 0;

    while(p1 || m1)
    {
        int x = (p1 ? p1->val : 0);
        int y = (m1 ? m1->val : 0);

        TotalSum = x + y +carry;

        carry = TotalSum / 10;

        tmpSum = TotalSum % 10;

        tmpNode = malloc(sizeof(struct ListNode));
        tmpNode->next = NULL;
        tmpNode->val = tmpSum;
        
        if (!retList)
        {
            retList = tmpNode;
            lastNode = retList;
        }
        else
        {
            lastNode->next = tmpNode;
            lastNode = tmpNode;
        }
        
        //go ahead
        if(p1)
            p1 = p1->next;

        if(m1)
            m1 = m1->next;
    }

    if (carry)
    {
        tmpNode = malloc(sizeof(struct ListNode));
        tmpNode->next = NULL;
        tmpNode->val = carry;

        if (!retList)
        {
            retList = tmpNode;
            lastNode = retList;
        }
        else
        {
            lastNode->next = tmpNode;
            lastNode = tmpNode;
        }
    }
    
    return retList;
}


int main()
{
    ListNode_init(&ListHead_1, 1, 3);
    ListNode_init(&ListHead_2, 2, 3);

    printf("List1:\n");
    print_list(&ListHead_1);

    printf("List2:\n");
    print_list(&ListHead_2);

    struct ListNode *newList = addTwoNumbers_optimized(ListHead_1.next, ListHead_2.next);
    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}

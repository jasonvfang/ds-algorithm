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
                       tmp->val = 4;
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p1 = NULL, *m1 = NULL;
    struct ListNode *retList = NULL, *LastNode = NULL, *tmpNode = NULL;
    
    p1 = l1;
    m1 = l2;

    //return another list if one of the list is not null.
    if (p1 == NULL)
        return m1;
        
    if (m1 == NULL)
        return p1;
    
    //Neither of the two lists are null.
    //Merge them into one list.
    while (p1 || m1)
    {
        if (p1 == NULL){
            tmpNode = m1;
            break;
        }

        if (m1 == NULL){
            tmpNode = p1;
            break;
        }

        if (p1->val > m1->val)
        {            
            if (retList == NULL){
                retList = m1;
                LastNode = m1;
            }
            else{
                LastNode->next = m1;
                LastNode = m1;
            }

            m1 = m1->next;
        }
        else
        {
            if (retList == NULL){
                retList = p1;
                LastNode = p1;
            }
            else{
                LastNode->next = p1;
                LastNode = p1;
            }

            p1 = p1->next;                
        }
    }

    while (tmpNode)
    {
         LastNode->next = tmpNode;
         LastNode = tmpNode;
         tmpNode = tmpNode->next;
    }
    
    return retList;
}

int main()
{
    ListNode_init(&ListHead_1, 1, 3);
    ListNode_init(&ListHead_2, 2, 4);

    printf("List1:\n");
    print_list(&ListHead_1);

    printf("List2:\n");
    print_list(&ListHead_2);

    struct ListNode *newList = mergeTwoLists(ListHead_1.next, ListHead_2.next);
    printf("New List:\n");
    print_list_noheader(newList);

    return 0;
}

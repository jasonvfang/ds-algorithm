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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };


struct ListNode *findMidNode(struct ListNode *head)
{
    if (NULL == head)
    {
        return NULL;
    }

    struct ListNode *prevPtr = NULL;
    struct ListNode *slowPtr = head;
    struct ListNode *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        prevPtr = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    if (prevPtr != NULL)
    {
        prevPtr->next = NULL;
    }

    return slowPtr;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if (NULL == head)
    {
        return NULL;
    }

    struct ListNode *midNode = findMidNode(head);

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = midNode->val;
    root->left = NULL;
    root->right = NULL;

    if (head == midNode){
        return root;
    }

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midNode->next);

    return root;
}


void traverse(struct TreeNode *root)
{
    if (root == NULL)
        return;

    if (root->left)
        traverse(root->left);
    
    printf(" %d ", root->val);
    
    if (root->right)
        traverse(root->right);
}

int main(int argc, char *argv[])
{
    ListNode_init(&ListHead_1, 1, 5);

    //printf("List:\n");
    //print_list(&ListHead_1);

    struct TreeNode* bst = sortedListToBST(ListHead_1.next);

    traverse(bst);

    return 0;
}

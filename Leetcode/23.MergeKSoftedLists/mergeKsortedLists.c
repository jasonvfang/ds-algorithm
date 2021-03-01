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
    struct ListNode *retList = NULL, *tail = NULL;
    
    p1 = l1;
    m1 = l2;

    //return another list if one of the list is not null.
    if (p1 == NULL)
        return m1;
        
    if (m1 == NULL)
        return p1;

    while (p1 || m1)
    {
        if (p1 == NULL){
            break;
        }

        if (m1 == NULL){
            break;
        }

        if (p1->val > m1->val)
        {            
            if (retList == NULL){
                retList = m1;
                tail = m1;
            }
            else{
                tail->next = m1;
                tail = m1;
            }

            m1 = m1->next;
        }
        else
        {
            if (retList == NULL){
                retList = p1;
                tail = p1;
            }
            else{
                tail->next = p1;
                tail = p1;
            }

            p1 = p1->next;                
        }
    }

    //Append the tail of unfetched list.
    if (p1)
    {
         tail->next = p1;
    }
    else if (m1)
    {
         tail->next = m1;
    }

    return retList;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode *retList = NULL;
    int i;

    if (listsSize <= 0 || lists == NULL)
        return NULL;

    retList = lists[0];

    for (i = 1; i < listsSize; i ++)
    {
        struct ListNode *tmpList = mergeTwoLists(lists[i], retList);
        if (tmpList != retList)
            retList = tmpList;
    }

    return retList;    
}


struct ListNode** partion(struct ListNode** lists, int start, int end) {
    if (start == end)
        return lists[start];
    if (start < end) {
        int middle = (start + end) / 2;
        struct ListNode* l1 = partion(lists, start, middle);
        struct ListNode* l2 = partion(lists, middle+1, end);
        return mergeTwoLists(l1, l2);
    } else {
        return NULL;
    }
}

struct ListNode* mergeKLists_optimized(struct ListNode** lists, int listsSize) {
    return partion(lists, 0, listsSize-1);
}


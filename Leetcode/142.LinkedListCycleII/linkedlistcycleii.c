/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *faster = head;
	struct ListNode *slower = head;
	
	if(head == NULL || head->next == NULL){
		return NULL;
	}
	
	slower = head->next;
	faster = slower->next;
	while(faster != slower){
		if(faster == NULL || faster->next == NULL)
		{
			return NULL;
		}
		
		faster = faster->next->next;
		slower = slower->next;
	}

    slower = head;
    while(slower != faster)
    {
        slower = slower->next;
        faster = faster->next;
    }

    return slower;
}


//C++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        while(head->next!=nullptr) {
            if(head->next->val==INT_MAX) return head->next; 
            else head->val=INT_MAX;
            head=head->next;
        }
        return nullptr;
    }
};
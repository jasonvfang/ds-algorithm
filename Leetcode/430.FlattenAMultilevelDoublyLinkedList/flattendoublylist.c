/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *previous = NULL;
    
    void flat(Node *head)
    {
        if(!head) return ;
        
        if(previous)
            previous->next = head;
            
        head->prev = previous;
        previous = head;
        
        Node *next = head->next;
        if(head->child)
        {
            Node *temp = head->child;
            flat(head->child);
            temp->prev = head;
            head->next = temp;
            head->child = NULL;
        }
        
        flat(next);
    }
    
    Node* flatten(Node* head) {
        flat(head);
        return head;
    }
};


class Solution {
public:
    Node* flatten(Node* head) {
        Node *ans, *temp = head, *anshead = NULL, *prev = NULL, *next, *end;
        
        if(!head) return NULL;
        anshead = head;
        
        stack<Node*> s;
        s.push(head);
        
        while(!s.empty())
        {
            temp = s.top();
            s.pop();
            
            if(prev) prev->next = temp;
            temp->prev = prev;
            prev = temp;
            
            if(temp->next) s.push(temp->next);
            if(temp->child) {s.push(temp->child); temp->child = NULL;}
        }
        
        return anshead;
    }
};

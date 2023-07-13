/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // this solution is without extra space
        if(head == NULL){
            return head;
        }
        
        // 1.   inserting into the immediate next
        Node* iter = head, *front;
        Node* copy;
        
        while(iter != NULL){
            front = iter->next;
            copy = new Node(iter->val, NULL, NULL);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
        // 2.   adding the random part
        
        iter = head;
        
        while(iter != NULL){
            if(iter->random != NULL){
                copy = iter->next;
                copy->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        
        // 3.   breaking the current bonds and replacing 
        
        Node* newHead = new Node(0, NULL, NULL);
        Node* dummy = newHead;
        
        iter = head;
        
        while(iter != NULL){
            
            front = iter->next->next;
            dummy->next = iter->next;
            iter->next = front;
            
            iter = front;
            dummy = dummy->next;
        }
        
        return newHead->next;
        
    }
};



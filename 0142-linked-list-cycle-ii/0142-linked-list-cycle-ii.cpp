/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        
        // using the tortoise and hare concept
        
        ListNode* slow  = head, *fast = head;
        
        
        if(head == NULL || head->next == NULL){
            // edge case
            return NULL;
        }
        
        // traverse and find the meeting point
        
        // to terminate the loop, the fast should not be null
        
        while(fast->next != NULL && fast->next->next != NULL){
            
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast){
                break;
            }
            
        }
        
        // now the loop has been terminated
        
        if(fast->next == NULL || fast->next->next == NULL){   
            // then there is no loop
            return NULL;
        }
        
        
        // loop is there
        
        fast = head;
        
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        
        return slow;
    }
};
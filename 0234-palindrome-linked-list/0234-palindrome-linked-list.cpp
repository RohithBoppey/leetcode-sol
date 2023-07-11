/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        
        // 1 or 0 elements
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        
        ListNode* curr = head, *prev = NULL, *next;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
        
    }
    
    
    
    bool isPalindrome(ListNode* head) {
    
        // instead of reversing all, we can find the other half and reverse it and then compare until the rest
        
        if(head == NULL || head->next == NULL){
            
            // 0 or 1 elements only
            
            return true;
            
        }
        
        
        ListNode* slow = head, *fast = head;
        
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        // now slow is pointing to the node to reverse
        
        ListNode* p2 = reverse(slow);
        ListNode* p1 = head;
        
        
        while(p2 != NULL){
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        
        return true;
        
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* temp, *curr = NULL;
        
        int sum = 0, carry = 0, q;
        
        // initially to the temp
        
        curr = result;
        
        while(l1 != NULL || l2 != NULL || carry == 1){
            
            // handling l1, l2 efficiently
            
            sum = carry;
            if(l1 != NULL) sum += l1->val;
            if(l2 != NULL) sum += l2->val;
            
            carry = sum / 10;
            q = sum % 10;
            
            temp = new ListNode(q);
            
            curr->next = temp;
            curr = curr->next;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            
        }
        
        // since the initial one is the dummy node
        
        return result->next;
        
    }
};
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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1 == NULL){
            return h2;
        }
        
        if(h2 == NULL){
            return h1;
        }
        
        
        // l1 is always low, l2 is always high
        if(h1->val > h2->val){
            return mergeTwoLists(h2, h1);
        }
        
        
        ListNode *l1 = h1, *l2 = h2, *result = h1;
        ListNode* temp = NULL;
        
        while(l1 != NULL && l2 != NULL){
            temp = l1;
            
            while(l1 != NULL && l1->val <= l2->val){
                // keep moving l1 and update temp
                temp = l1;
                l1 = l1->next;
            }
            
            temp->next = l2;
            swap(l1, l2);
        }
        
        
        return result;
        
    }
};
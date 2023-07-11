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
    
    ListNode* helper(ListNode* head, int left, int k){
        
        
        if(left < k){
            // less than current group
            // so return head
            return head;
        }
        
        
        // we need to rotate the first k elements
        
        int count = 0;
        ListNode *curr = head, *prev = NULL, *next;
        
        while(count < k && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
            left--;
        }
        
        // once the k nodes are rotated
        // head points to first element and prev points to the last element
        // next points to next element
        
        if(next != NULL){
            head->next = helper(next, left, k);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int currCount = 0;
        ListNode* temp = head;
        while(temp != NULL){
            currCount++;
            temp = temp->next;
        }
        return helper(head, currCount, k);
    }
};
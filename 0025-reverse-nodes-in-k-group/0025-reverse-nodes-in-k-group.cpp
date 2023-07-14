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
    
    int findLen(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        
        return count;
    }
    
    
    ListNode* solve(ListNode* head, int left, int k){
        
        // this function return the reversed by k group linked list
        
        if(left < k){
            // cannot reverse, left elements are less than k
            return head;
        }
        
        // rotate the k group from the head position
        
        ListNode* curr = head, *next, *prev = NULL;
        
        int count = 0;
        
        while(curr != NULL && count < k){
            // since we are required to only rotate k elements
            
            // 4 operations to rotate
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            // to manage
            count++;
            left--;
        }
        
        
        // now the k group has been rotated
        // the new list contains the head to be the last element pointing to NULL
        
        // that we are updating from the later on recursive call
        
        if(next != NULL){
            head->next = solve(next, left, k);
        }
        
        return prev;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            // 0 or 1 elements
            // nothing to rotate
            return head;
        }
        
        int count = findLen(head); // this function gives the len of the linked list
        
        return solve(head, count, k);
        
    }
};
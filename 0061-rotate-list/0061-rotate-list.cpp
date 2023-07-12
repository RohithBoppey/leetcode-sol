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
    
    // this function gives the length of the linked list
    
    int lengthOfLL(ListNode* head){
        int n = 0;
        while(head != NULL){
            n++;
            head = head->next;
        }
        return n;
    }
    
    ListNode* rotate(ListNode* head, int len){
        ListNode* curr = head, *next;
        
        while(len != 2){
            curr = curr->next;
            len--;
        }
        
        next = curr->next;
        
        // break the link and make the link
        curr->next = NULL;
        next->next = head;
        
        return next;
        
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            // 0 or 1 element
            return head;
        }
        
        
        // else you need to rotate (n % k) times
        
        int n = lengthOfLL(head);
        int c = k % n;
        
        while(c != 0){
            head = rotate(head, n);
            c--;
        }
        
        return head;
        
    }
};
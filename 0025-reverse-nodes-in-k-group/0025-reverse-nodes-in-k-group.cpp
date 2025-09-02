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
    int findCount(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* solve(ListNode* head, int left, int k){
        // how much is left, how much to rotate
        if(left < k){
            // should not rotate
            return head; 
        }

        ListNode* curr = head, *next, *prev = NULL; 
        int c = 0; 

        while(curr != NULL && c < k){
            next = curr->next; 
            curr->next = prev; 
            prev = curr;
            curr = next; 

            left--;
            c++;
        }

        // now the first k nodes are reversed, join this with the remaining part
        // head is the first node
        if(next != NULL){
            head->next = solve(next, left, k);
        }

        return prev; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = findCount(head);
        ListNode* h = solve(head, count, k);
        return h;   
    }
};
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
    // first completing the reverse linked list function
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *curr = head, *next;
        while(curr != NULL){
            next = curr->next; 
            curr->next = prev; 
            prev = curr;
            curr = next; 
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // choose the start and end of the positions
        ListNode* leftPrev = head, *rightNext, *curr = head; 
        // to prevent the left = 1 condition
        ListNode* dummy = new ListNode(0);

        dummy->next = head; 
        curr = dummy; 

        // move until the current is pointing to the left position node
        for(int i = 1; i <= left; i++){
            leftPrev = curr; 
            curr = curr->next;
        } 

        // sublist head and sublist tail
        ListNode* sh = curr, *st = curr; 

        // move the right pointer until it meets the right position
        for(int i = 0; i < right - left; i++){
            st = st->next;
        }

        rightNext = st->next; 
        st->next = NULL;

        // now reverse the subpart
        leftPrev->next = reverse(sh);
        sh->next = rightNext; 

        return dummy->next;

    }
};
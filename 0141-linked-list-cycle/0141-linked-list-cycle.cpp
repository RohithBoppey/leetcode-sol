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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            // if null then it is not containing a cycle
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                // contains a cycle
                return true;
            }
        }

        // if breaking, no loop
        return false;
    }
};
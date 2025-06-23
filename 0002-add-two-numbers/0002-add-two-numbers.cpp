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
        ListNode* result = new ListNode(0);

        int sum = 0, carry = 0;
        ListNode* curr = result;

        while(l1 != NULL || l2 != NULL || carry == 1){
            // add that to sum
            sum = 0;
            sum += (l1 != NULL) ? l1->val : 0;
            sum += (l2 != NULL) ? l2->val : 0;

            // add carry as well
            sum += carry; 
            carry = 0;

            if(sum >= 10){
                carry = 1;
                sum -= 10;
            }

            // add the corresponding value to the ListNode
            ListNode* t = new ListNode(sum);
            curr->next = t;
            curr = curr->next; 

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;

        }

        return result->next;
    }
};
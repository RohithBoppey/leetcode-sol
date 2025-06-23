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
    ListNode* addTwo(ListNode* l1, ListNode* l2) {
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

    ListNode* reverse(ListNode* l){
        if(!l || !l->next){
            // single or no node
            return l;
        }

        // start reversing
        ListNode* curr = l, *prev = NULL, *next; 

        while(curr != NULL){
            next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next;
        }

        return prev; 
    }

    void printLL(ListNode* l){
        while(l != NULL){
            cout << l->val << "->";
            l = l->next;
        }
        cout << endl; 
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2); 

        // printLL(l1);
        // printLL(l2);

        ListNode* result = addTwo(l1, l2);

        result = reverse(result);

        return result;    
    }
};
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
    void printLL(ListNode* head){
        ListNode* curr = head;
        while(curr != NULL){
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << endl;
    }

    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL){
            return NULL;
        }

        if(head->next == NULL){
            // only one value exists
            return (head->val == val) ? NULL : head;
        }

        ListNode* prev = new ListNode(0, NULL), *curr = head, *next = head->next;
        prev->next = head; 

        ListNode* newHead = prev;

        while(curr != NULL){
            if(curr->val == val){
                prev->next = next;
            } else{
                prev = prev->next;
            }
            curr = curr->next;
            if(next != NULL){
                next = next->next;
            }
            // printLL(prev);
        }

        return newHead->next;

    }
};
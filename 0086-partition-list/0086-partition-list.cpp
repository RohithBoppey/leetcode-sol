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
    
    void printLinkedList(ListNode* head){
        ListNode* curr = head;
        while(curr != NULL){
            cout << curr->val << "->"; 
            curr = curr->next;
        }
        cout << endl;
    }
    
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL || head->next == NULL){
            // 0 or 1 elements
            // nothing to do
            return head;
        }
        
        ListNode* less = new ListNode(0), *temp1, *more = new ListNode(0), *temp2;
        
        temp1 = less;
        temp2 = more;
        
        // populate
        while(head != NULL){
            if(head->val >= x){
                // more
                temp2->next = new ListNode(head->val);
                temp2 = temp2->next;
            }
            
            else{
                // less
                temp1->next = new ListNode(head->val);
                temp1 = temp1->next;
            }
            head = head->next;
        }
        
        
        // join more and less
        // traverse 'less' and join last with more
        
        temp1 = less;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        
        temp1->next = more->next;
        
        return less->next;
    }
};
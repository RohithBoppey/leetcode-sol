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
        
        // making a new list for >= x
        ListNode* newHead = new ListNode(0), *temp;
        
        temp = newHead;
        
        ListNode* curr = head, *prev = NULL, *next;
        
        while(curr != NULL){
            if(curr->val >= x){
                // delete from the current list
                if(prev == NULL){
                    // first element is trying to be removed
                    head = head->next;
                }else{
                    prev->next = curr->next; 
                }
                
                // add into the new list
                int val = curr->val;
                
                temp->next = new ListNode(val);
                temp = temp->next;
                
                curr = curr->next;
            }    
            
            else{
                // didnt delete the current element
                prev = curr;
                curr = curr->next;
            }
        }
        
        // printLinkedList(head);
        // printLinkedList(newHead);
        
        // join the new nodes
        if(prev == NULL){
            return newHead->next;
        }
        prev->next = newHead->next;
        return head;
    }
};
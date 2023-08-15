​![WhatsApp Image 2023-08-15 at 16 43 02](https://user-images.githubusercontent.com/73538974/260700490-3ad83884-8462-4967-9d8f-1428fa1f9141.jpg)
      
      
CODE 1: USING SINGLE LIST + DELETION OF > ELEMENTS CONCEPT
```
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
```

CODE 2: USING 2 LISTS (SLOWER):
```
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
```

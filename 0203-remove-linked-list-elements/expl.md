The one thing to understand from here is this: 

For the linked list problems which needs rmeoving, changing the linked list in any way in either of these 3 cases: remove the element from the front, middle or at the end - use prev as the new Node and assign it to the current head, and while returning head, you can do return head->next;

```c++
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
```

Some edge cases for single element, no element in the linked list. Other than that, few things: 
1. Have 3 pointers side by side, if curr=val --> only change the prev->next so that the link between prev and curr gets removed, but prev will not get changed. 0 -> 6 -> 1 will now become 0->1 and prev is stil pointing at 0
2. For every iteration, curr and next is pakka changed - by a step, but for prev, it only depends on the value == val condition
3. At the end, next needs to be handled properly for the tail node to be the value == val node.

![WhatsApp Image 2024-12-07 at 16 44 32_995bf5b9](https://github.com/user-attachments/assets/3efcf2c3-6fca-4a01-95cc-8e9c7aa73f8e)

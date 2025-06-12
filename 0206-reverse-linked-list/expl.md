[Ref](https://dev.to/jacobjzhang/a-visual-guide-to-reversing-a-linked-list-161e)

![image](https://github.com/user-attachments/assets/3379235b-9c68-4623-b20f-37ca95212c07)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head, *prev = NULL, *next;
        
        if(head == NULL || head->next == NULL){
            return head;
        }

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;

    }
};
```

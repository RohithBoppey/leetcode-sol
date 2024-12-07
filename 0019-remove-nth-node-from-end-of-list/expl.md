​![WhatsApp Image 2023-07-08 at 17 00 51](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/8bf7ffd0-aae5-4c61-b43c-5654128924e0)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* main = head, *sub = head;

        if(head->next == NULL){
            return NULL;
        }

        while(n != 0){
            sub = sub->next;
            n--;
        }

        if(sub == NULL){
            return head->next;
        }

        while(sub->next != NULL){
            main = main->next;
            sub = sub->next;
        }

        // now main points to the location where we need to remove the link
        main->next = main->next->next;

        return head;

    }
};
```

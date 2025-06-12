Idea:
- put the lower linked list first and then the higher one next
- for each node, check l1 val and l2 val, and if l1 is > l2, pick the node and put in l1

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
    ListNode* merge(ListNode* l1h, ListNode* l2h){

        ListNode* prev = new ListNode(0), *head = l1h, *next = NULL;
        prev->next = l1h;

        while(l1h != NULL && l2h != NULL){
            if(l1h->val > l2h->val){
                // pull the node from l2 and put in l1
                next = l2h->next;
                prev->next = l2h;
                l2h->next = l1h;
                l2h = next;
            }else{
                l1h = l1h->next;
            }
            prev = prev->next;
        }

        // if l2 is remaining with any elements
        if(l2h != NULL){
            prev->next = l2h;
        }

        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        // choose the smaller one
        return (l1->val < l2->val) ? merge(l1, l2) : merge(l2, l1); 
    }
};
```​

![WhatsApp Image 2023-07-08 at 16 44 08](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/afa031ee-eda7-4faf-a1e5-091962fbe911)

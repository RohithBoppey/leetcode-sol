​+ keep 2 pointers -> slow & fast, initially at head, so they coincide
+ move them, and if fast becomes NULL means end of the linked list => confirming no loop
+ if they coincide, loop exists

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            // if null then it is not containing a cycle
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                // contains a cycle
                return true;
            }
        }

        // if breaking, no loop
        return false;
    }
};
```


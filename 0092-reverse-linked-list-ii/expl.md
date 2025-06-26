- this code is utilising the existing code for reversing a linked list
- if observed, we need 4 pointers to be precise - leftPrev, sublistHead, sublistTail, rightNext
- and to handle the case `left = 0`, giving a dummy node and next to head
- first move until you reach the sublistHead which is the prev position, then leftPrev is also found out right?
- using the st, sh pointers, move the st pointer to a place where this is ending
- now remove the st->next and reverse the sh pointer
- attach the remaining nodes correctly

```c++
class Solution {
public:
    // first completing the reverse linked list function
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *curr = head, *next;
        while(curr != NULL){
            next = curr->next; 
            curr->next = prev; 
            prev = curr;
            curr = next; 
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // choose the start and end of the positions
        ListNode* leftPrev = head, *rightNext, *curr = head; 
        // to prevent the left = 1 condition
        ListNode* dummy = new ListNode(0);

        dummy->next = head; 
        curr = dummy; 

        // move until the current is pointing to the left position node
        for(int i = 1; i <= left; i++){
            leftPrev = curr; 
            curr = curr->next;
        } 

        // sublist head and sublist tail
        ListNode* sh = curr, *st = curr; 

        // move the right pointer until it meets the right position
        for(int i = 0; i < right - left; i++){
            st = st->next;
        }

        rightNext = st->next; 
        st->next = NULL;

        // now reverse the subpart
        leftPrev->next = reverse(sh);
        sh->next = rightNext; 

        return dummy->next;

    }
};
```

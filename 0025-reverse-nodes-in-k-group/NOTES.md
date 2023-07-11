12345 and k == 2
imagine we are somehow rotating the first k nodes
then the previous is being returned, and the remaining nodes should be combined with the head->next

![image](https://user-images.githubusercontent.com/73538974/252662184-5e0c52a2-55dd-41c4-be2e-5c742036d2a9.png)
![image](https://user-images.githubusercontent.com/73538974/252662299-3aa2109c-6dc8-4a7c-b914-27941f9ef787.png)

and the call should be for next only when it is not null​

this is just BETTER SOLUTION, NOT OPTIMAL

```
class Solution {
public:
    
    ListNode* helper(ListNode* head, int left, int k){
        
        
        if(left < k){
            // less than current group
            // so return head
            return head;
        }
        
        
        // we need to rotate the first k elements
        
        int count = 0;
        ListNode *curr = head, *prev = NULL, *next;
        
        while(count < k && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
            left--;
        }
        
        // once the k nodes are rotated
        // head points to first element and prev points to the last element
        // next points to next element
        
        if(next != NULL){
            head->next = helper(next, left, k);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int currCount = 0;
        ListNode* temp = head;
        while(temp != NULL){
            currCount++;
            temp = temp->next;
        }
        return helper(head, currCount, k);
    }
};
```

FOR OPTIMAL ONE:



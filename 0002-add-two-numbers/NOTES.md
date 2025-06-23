![image](https://user-images.githubusercontent.com/73538974/251970704-bdcc8321-1484-42b9-9db7-81f70e8367ee.png)         
          
![WhatsApp Image 2023-07-08 at 17 25 26](https://user-images.githubusercontent.com/73538974/251970992-56a21b83-3292-4c63-8060-bb5ae961eb2d.jpg)
​
- one thing is that both the linked lists need not be the same length
- so the loop should continue until either of the one is not null and also if the carry = 1 (to handle the last new element case)
- and for each iteration, sum is based on l1, l2 and carry value and if sum > 10, carry = 1, and sum -= 10
- this continues so on
- make a node each time and insert it in the linked list

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);

        int sum = 0, carry = 0;
        ListNode* curr = result;

        while(l1 != NULL || l2 != NULL || carry == 1){
            // add that to sum
            sum = 0;
            sum += (l1 != NULL) ? l1->val : 0;
            sum += (l2 != NULL) ? l2->val : 0;

            // add carry as well
            sum += carry; 
            carry = 0;

            if(sum >= 10){
                carry = 1;
                sum -= 10;
            }

            // add the corresponding value to the ListNode
            ListNode* t = new ListNode(sum);
            curr->next = t;
            curr = curr->next; 

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;

        }

        return result->next;
    }
};
```

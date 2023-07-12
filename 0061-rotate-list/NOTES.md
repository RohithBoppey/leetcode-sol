My solution: Using rotate once function and calling it k % n times (Accepted ✅ but slow)

![WhatsApp Image 2023-07-12 at 18 20 39](https://user-images.githubusercontent.com/73538974/252976516-ac0e80c7-3328-46da-aa76-ea2a7b8e27b9.jpg)

Code:   
```
class Solution {
public:
    
    // this function gives the length of the linked list
    
    int lengthOfLL(ListNode* head){
        int n = 0;
        while(head != NULL){
            n++;
            head = head->next;
        }
        return n;
    }
    
    ListNode* rotate(ListNode* head, int len){
        ListNode* curr = head, *next;
        
        while(len != 2){
            curr = curr->next;
            len--;
        }
        
        next = curr->next;
        
        // break the link and make the link
        curr->next = NULL;
        next->next = head;
        
        return next;
        
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            // 0 or 1 element
            return head;
        }
        
        
        // else you need to rotate (n % k) times
        
        int n = lengthOfLL(head);
        int c = k % n;
        
        while(c != 0){
            head = rotate(head, n);
            c--;
        }
        
        return head;
        
    }
};
```


There is an optimal solution even better: finding (n - k) elements and then making and breaking the link        

![image](https://user-images.githubusercontent.com/73538974/252979395-9000df67-3d4e-42da-9f99-b14c6cc91185.png)
      
DRY RUN ON EXAMPLE CASES:   

![image](https://user-images.githubusercontent.com/73538974/252982903-b35caf1d-32c9-4bf6-af78-5f1d2145b6df.png)
![image](https://user-images.githubusercontent.com/73538974/252983709-c66eceab-f16c-46ef-9d18-22ffc032d4ab.png)

​

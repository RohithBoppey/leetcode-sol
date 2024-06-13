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

```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head == NULL || k == 0){
            // cannot do anything
            return head;
        }
        
        // we need to find the count
        
        ListNode* temp = head, *last;
        
        int count = 0;
        
        while(temp != NULL){
            
            count++;
            
            last = temp;
            temp = temp->next;
        }
        
        // last would be pointing to the last element now
        
        last->next = head;
        
        // circular has been done
        
        // we need to break the find the n % k element and break the link
        
        k = k % count;
        int c = 0, t = count - k - 1;
        
        temp = head;
        
        while(c != t){
            c++;
            temp = temp->next;
        }
        
        // now temp would be pointing to the n - k element
        
        // assinging new head
        head = temp->next;
        
        // breaking the bond
        temp->next = NULL;
        
        return head;
        
    }
```

DRY RUN ON EXAMPLE CASES:   

![image](https://user-images.githubusercontent.com/73538974/252982903-b35caf1d-32c9-4bf6-af78-5f1d2145b6df.png)
![image](https://user-images.githubusercontent.com/73538974/252983709-c66eceab-f16c-46ef-9d18-22ffc032d4ab.png)

​

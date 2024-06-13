​![image](https://user-images.githubusercontent.com/73538974/253219282-5c73fcc6-3ec5-4a8f-a009-a19af6943d50.png)     

using hashmap to copy the node and re assign it based on the hashmap

![image](https://user-images.githubusercontent.com/73538974/253219393-f8784e19-5c66-45ab-bdf1-144c4ec8daf2.png)


```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // using hashmap to hash the pointers
        
        Node* temp = head;
        
        unordered_map<Node*, Node*> mp;
        
        while(temp != NULL){
            // create a new copy of it
            
            Node* copy = new Node(temp->val, NULL, NULL);
            mp[temp] = copy;
            temp = temp->next;
        }
        
        // now copy is created
        // nowe re assign based on that
        
        temp = head;
        
        while(temp != NULL){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            
            temp = temp->next;
        }
        
        return mp[head];
        
    }
};
```

tc: O(N) + O(N)
sc: O(N)

WITHOUT EXTRA SPACE: OPTIMAL

![image](https://user-images.githubusercontent.com/73538974/253219698-de5311e7-5afa-4ab2-a51c-80ca7ab5ae50.png)     

```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // this solution is without extra space
        if(head == NULL){
            return head;
        }
        
        // 1.   inserting into the immediate next
        Node* iter = head, *front;
        Node* copy;
        
        while(iter != NULL){
            front = iter->next;
            copy = new Node(iter->val, NULL, NULL);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
        // 2.   adding the random part
        
        iter = head;
        
        while(iter != NULL){
            if(iter->random != NULL){
                copy = iter->next;
                copy->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        
        // 3.   breaking the current bonds and replacing 
        
        Node* newHead = new Node(0, NULL, NULL);
        Node* dummy = newHead;
        
        iter = head;
        
        while(iter != NULL){
            
            front = iter->next->next;
            dummy->next = iter->next;
            iter->next = front;
            
            iter = front;
            dummy = dummy->next;
        }
        
        return newHead->next;
        
    }
};

```

tc: O(N) + O(N) + O(N)
sc: O(1) no extra space, we are inserting into the list


ADDING A NEW NODE INTO THE DOUBLY LINKED LIST:    
      
![image](https://user-images.githubusercontent.com/73538974/254301786-10c44e43-70e3-4f05-8353-90d5a16f9e6c.png) 
      
DELETING A NODE FROM THE DOUBLY LINKED LIST:      
       
![image](https://user-images.githubusercontent.com/73538974/254302062-24bbcf57-4a89-4f34-8111-fc3f3caccfd6.png)
      
DRY RUN:    
        
![image](https://user-images.githubusercontent.com/73538974/254300851-cd6207f7-5206-4ecc-879c-32067dc6bf48.png)
![image](https://user-images.githubusercontent.com/73538974/254300907-69b40a35-99f9-40a0-b795-3159e64d2120.png)
![image](https://user-images.githubusercontent.com/73538974/254300939-e6fe9d44-9f6c-4273-acfd-c486d8a573a2.png)
![image](https://user-images.githubusercontent.com/73538974/254300989-aaefcb33-0ed1-48f9-a79f-0d6cb0163003.png)
![image](https://user-images.githubusercontent.com/73538974/254301216-bf52d83b-bc0c-4164-b6e4-2fb7616232e1.png)
![image](https://user-images.githubusercontent.com/73538974/254301308-ecab6db6-3aac-48e9-9183-8d0977590682.png)
![image](https://user-images.githubusercontent.com/73538974/254301368-408b2c84-1c3d-458c-8aee-df1fab38ef11.png)
![image](https://user-images.githubusercontent.com/73538974/254301418-4b831cf2-5e11-4f86-9aac-c04bae6f88d0.png)
![image](https://user-images.githubusercontent.com/73538974/254301450-001c1dcc-6557-42cd-bdc5-ed885b7aff73.png)

```
class LRUCache {
public:
//     what do we require
//     we need to implement a doubly linked list and along with their methods
    class node{
      public:
        int key;
        int value;
        node* prev;
        node* next;
        node(int k, int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
//     additional things we need
    int cap;
    unordered_map<int, node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(node* temp){
        node* prevNode = temp->prev;
        node* nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        // delete(temp);
    }
    
    void addNode(node* temp){
        node* t = head->next;
        head->next = temp;
        temp->prev = head;
        t->prev = temp;
        temp->next = t;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        node* newNode = new node(key, value);
        if(mp.find(key) != mp.end()){
//             some value already present at that index
            node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
//         now inorder to add it back
        if(cap == mp.size()){
//             remove the least recently used element
//             which is always present at the before tail node
            node* del = tail->prev;
            int k = del->key;
            deleteNode(del);
            mp.erase(k);
        }
        
//         now we have free space to insert our element
        addNode(newNode);
        mp[key] = head->next;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

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
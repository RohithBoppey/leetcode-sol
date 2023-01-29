class LFUCache {
public:
    
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        int count;
        Node(int k, int v){
            key = k;
            val = v;
            count = 1;
        }
    };
    
    struct List{
        int size;
        Node* head;
        Node* tail;
        List(){
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        
        void addFront(Node* newNode){
            Node* temp = head->next;
            newNode->next = temp;
            head->next = newNode;
            newNode->prev = head;
            temp->prev = newNode;   
            size++;
        }
        
        void removeEnd(Node* delNode){
            Node* delPrev = delNode->prev;
            Node* delNext = delNode->next;
            delPrev->next = delNext;
            delNext->prev = delPrev;
            size--;
        }
        
    };
    
    
    map<int, Node*> keyVal;
    map<int, List*> freqList;
    
    int maxCacheSize, currSize, minFreq;
    
    LFUCache(int capacity) {
        maxCacheSize = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateNodeFreq(Node* node){
        keyVal.erase(node->key);
        freqList[node->count]->removeEnd(node);
        if(node->count == minFreq && freqList[node->count]->size == 0){
//             that freq list is empty
            minFreq++;
        }
        
        List* newList = new List();
        if(freqList.find(node->count + 1) != freqList.end()){
//             it is not present in the newer list as well
            newList = freqList[node->count + 1];
        }
        node->count += 1;
        newList->addFront(node);
        freqList[node->count] = newList;
        keyVal[node->key] = node;
    }
    
    int get(int key) {
//         check if the key is present
        if(keyVal.find(key) != keyVal.end()){
//             already present
            Node* temp = keyVal[key];
            int value = temp->val;
            updateNodeFreq(temp);
            return value;
        } 
        
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCacheSize == 0){
            return;
        }
        
        if(keyVal.find(key) != keyVal.end()){
//             already present
            Node* node = keyVal[key];
            node->val = value;
            updateNodeFreq(node);
        }else{
            if(currSize == maxCacheSize){
                List* list = freqList[minFreq];
                keyVal.erase(list->tail->prev->key);
                freqList[minFreq]->removeEnd(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* freq = new List();
            if(freqList.find(minFreq) != freqList.end()){
                freq = freqList[minFreq];
            }
            Node* node = new Node(key, value);
            freq->addFront(node);
            keyVal[key] = node;
            freqList[minFreq] = freq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
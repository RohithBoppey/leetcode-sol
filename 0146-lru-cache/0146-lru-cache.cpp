class LRUCache {
public:
    
    class node {
        public:
            pair<int,int> val;
            node* prev;
            node* next;
        
        // initialising each node
        node(){
            val = {0,0};
            prev = NULL;
            next = NULL;
        }
        
        node(pair<int, int>& p){
            val = p;
            prev = NULL;
            next = NULL;
        }
        
    };
       
    // required parameters
    node *head;
    node *tail;
    
    unordered_map<int, node*> amp; // amp -> {key, address} mapping
    
    int cap; // upper limit
    
    LRUCache(int capacity) {
        cap = capacity;
        // initialise new nodes
        head = new node();
        tail = new node();
        
        // base case
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
    }
    
    void printDLL(){
        node* t = head;
        while(t != NULL){
            cout << '{' << t->val.first << "," << t->val.second << "}->" ;
            t = t->next;
        }
        cout << endl;
    }
    
    node* addNodeToBegin(int val, int key){
        pair<int,int> p = {val, key};
        node* t = new node(p);
        node* next = head->next;
        
        head->next = t;
        t->next = next;
        next->prev = t;
        t->prev = head;
        
        return t;
    }
    
    /*
        check if present in vmp -> {return value, update DLL}
        yes -> pop from amp -> add to begining -> update amp
        no -> return -1
    */
    
    void deleteNode(node* d) {
        node* p = d->prev;
        node* n = d->next;
        
        p->next = n;
        n->prev = p;
    }
    
    
    int get(int key) {
        // cout << "get " << endl;
        node* curr;
        int val;
        if(amp.find(key) != amp.end()){
            curr = amp[key];
            val = curr->val.second;
            deleteNode(curr);
            curr = addNodeToBegin(key, val);
            amp[key] = curr;
            // printDLL();
            return val;
        }
        return -1;
    }
    
    /*
        check if present in vmp -> {update DLL or add to DLL}
        yes -> get(key) -> update vmp
        no -> check size == cap
            -> yes -> remove end node -> pop end node address -> pop from vmp ->  add to begining -> update amp
            -> no -> add to begin, done
    */
    
    void put(int key, int value) {
        node* t;
        if(amp.find(key) != amp.end()){
            // exists
            t = amp[key];
            t->val.second = value;
            get(key);
            return;
        }
        // cout << "put  " << endl;
        // not present, so should add
        int lv;
        if(amp.size() == cap){
            // remove last
            // cout << "del " << endl;
            // cout << tail->prev->val.first << " " << tail->prev->val.second << endl;
            lv = tail->prev->val.first;
            deleteNode(tail->prev);
            amp.erase(lv);
        }
        t = addNodeToBegin(key, value);
        amp[key] = t;
        // printDLL();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
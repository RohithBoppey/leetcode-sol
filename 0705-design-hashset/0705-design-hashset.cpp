class MyHashSet {
public:
    
    vector<bool> res;
    
    MyHashSet() {
        res.resize(1000001, false);
    }
    
    void add(int key) {
        res[key] = true;
    }
    
    void remove(int key) {
        res[key] = false;   
    }
    
    bool contains(int key) {
        return res[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
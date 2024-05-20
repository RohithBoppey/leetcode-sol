class MyQueue {
public:
    
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        // push into non-empty ones
        // if(!s2.empty()){
        //     s2.push(x);
        // }else{
        //     // either s1 can be empty, or non-empty, so win-win!
        //     s1.push(x);
        // }
        
        s1.push(x);
    }
    
    // move all from s1 to s2 until just one element remains in the stack
    // again move/pop based on method
    // push all those back to s1 
    // return the first
    
    int move(stack<int>& s1, stack<int>& s2, int method){
        int first;
        while(s1.size() != 1){
            first = s1.top();
            s1.pop();
            s2.push(first);
        }
        
        // just one element remains
        first = s1.top();
        s1.pop();
        
        if(method == 0){
            // just top, so we want this element
            s2.push(first);
        }
        
        // push all those elements back into the s1
        int t;
        while(!s2.empty()){
            t = s2.top();
            s2.pop();
            s1.push(t);
        }
        
        return first;
    }
    
    int pop() {
        int first;
        // if(!s1.empty()){
        //     first = move(s1, s2, 1);
        // }else{
        //     first = move(s2, s1, 1);
        // }
        first = move(s1, s2, 1);
        return first;
    }
    
    int peek() {
        int first ;
        // if(!s1.empty()){
        //     first = move(s1, s2, 0);
        // }else{
        //     first = move(s2, s1, 0);
        // }
        first = move(s1, s2, 0);
        return first;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
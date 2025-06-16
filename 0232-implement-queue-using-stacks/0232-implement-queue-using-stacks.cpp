class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        // push all into the stack s1
        // s2 acts as helper stack
        s1.push(x);
    }
    
    // if method == 0 -> top, if 1 -> then pop
    int transfer(int method = 0){   
        // always move from s1 to s2
        int top = -1;
        while(s1.size() > 1){
            top = s1.top();
            s1.pop();
            s2.push(top);
        }

        top = s1.top();
        s1.pop();
        if(method == 1){
            // pop: remove that element as well
        }else{
            // top: can push back
            s2.push(top);
        }

        // helper method done
        // so push back into main stack
        while(!s2.empty()){
            int t = s2.top();
            s2.pop();
            s1.push(t);
        }
        
        return top;

    }

    int pop() {
        return transfer(1);
    }
    
    int peek() {
        return transfer();
    }
    
    bool empty() {
        return s1.empty();
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
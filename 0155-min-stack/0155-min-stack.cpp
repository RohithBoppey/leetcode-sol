class MinStack {
public:
    stack<int> mn, main;

    MinStack() {
        
    }
    
    void push(int val) {
        main.push(val);
        if(mn.empty() || mn.top() >= val){
            mn.push(val);
        }
    }
    
    void pop() {
        int val = main.top();
        main.pop();
        if(!mn.empty() && mn.top() == val){
            mn.pop();
        }
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
    
    // declaring 2 stacks - main and min
    stack<int> main;
    stack<int> mn;
    
    MinStack() {
        // nothing to do
        // since they are already empty
    }
    
    void push(int val) {
        // direct push into main stack
        main.push(val);
        
        // logic while pushing into min stack
        if(mn.empty() || mn.top() >= val){
            // ours would be the new min
            mn.push(val);
        }
    }
    
    void pop() {
        int t = main.top();
        main.pop();
        
        // remove only when the top is coinciding
        if(t == mn.top()){
            mn.pop();
        }
    }
    
    int top() {
        int t = main.top();
        return t;
    }
    
    int getMin() {
        int t = mn.top();
        return t;
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
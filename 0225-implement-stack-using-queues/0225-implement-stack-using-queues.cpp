class MyStack {
public:
    queue<int> q1, q2; 

    MyStack() {
        
    }
    
    void push(int x) {
        // push into whichever is not empty
        !q2.empty() ? q2.push(x) : q1.push(x);
    }
    
    // transfer all the entries from q2 into q1
    int transfer(queue<int>& q1, queue<int>& q2, int sz = 0) {
        int last = -1;
        while (q2.size() > sz) {
            last = q2.front();
            q2.pop();
            q1.push(last);
        }
        if (sz == 1 && !q2.empty()) {
            last = q2.front(); // Get the last one to return
            q2.pop();          // Pop the last (top of stack)
        }
        return last;
    }

    int pop() {
        return q1.empty() ? transfer(q1, q2, 1) : transfer(q2, q1, 1);
    }
    
    int top() {
        return q1.empty() ? transfer(q1, q2) : transfer(q2, q1);
    }
    
    bool empty() {
        return q2.empty() && q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
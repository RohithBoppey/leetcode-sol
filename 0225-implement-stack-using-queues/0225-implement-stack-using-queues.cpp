class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {}

    void push(int x) {
        // push into the non-empty queue
        !q1.empty() ? q1.push(x) : q2.push(x); 
    }

    // Transfer all except 'sz' elements from q2 to q1
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
        // pull all elements from one queue to another queue
        int last; 
        if(q1.empty()){
            last = transfer(q1, q2, 1);
        }else{
            last = transfer(q2, q1, 1);
        }
        return last;
    }

    int top() {
        int last; 
        if(q1.empty()){
            last = transfer(q1, q2);
        }else{
            last = transfer(q2, q1);
        }
        return last;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};

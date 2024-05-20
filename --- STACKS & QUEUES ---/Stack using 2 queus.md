LEETCODE LINK: [HERE](https://leetcode.com/problems/implement-stack-using-queues/submissions/)

```c++
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
    
    }
    
    void push(int x) {
        if(empty()){
            // both are empty
            q1.push(x);
            return;
        }
        
        // push into the non empty one
        if(!q1.empty()){
            q1.push(x);
        }else{
            q2.push(x);
        }
    }
    
    // move all elements from q1 (non-empty) to q2 (empty) and return the last element
    // method = 0 -> top, method = 1 -> pop
    int move(queue<int>& q1, queue<int>& q2, int method){
        int last;
        while(q1.size() != 1){
            last = q1.front();
            q1.pop();
            q2.push(last);
        }
        // single element left in q1
        last = q1.front();
        q1.pop();
        
        if(method == 0){
            q2.push(last);
        }        
        
        return last;
    }
    
    int pop() {
        // find which is non-empty, and move to the empty one
        int last;
        if(!q1.empty()){
            // then move from q1 to q2 until last element
            last = move(q1, q2, 1);
        }else{
            // q2 not empty, so from q2 to q1
            last = move(q2, q1, 1);
        }
        return last;
    }
    
    int top() {
        int last;
        if(!q1.empty()){
            last = move(q1, q2, 0);
        }else{
            last = move(q2, q1, 0);
        }
        return last;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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
```
    
![WhatsApp Image 2024-05-20 at 23 24 21_e11f98ac](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/4d4b5c7c-06df-42d4-a031-a9edae6d00c8)

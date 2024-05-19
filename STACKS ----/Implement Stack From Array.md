+ A stack is a linear data structure which supports insertion and deletion only from the end => called the top of the stack.
+ can be implemented using `array` / `linked list`
+ Use an variable - `top` to show the top of the stack -> single variable can be enough as we only need to know about the top.
    
Simple solution using C++
```c++
// DEFINE Max COUNT HERE
# define MAX_COUNT_FOR_STACK 5

class Stack {
private:
    int top;
    int arr[MAX_COUNT_FOR_STACK];
public:
    Stack() {top = -1;}
    void push(int a){
        top++;
        if(top == MAX_COUNT_FOR_STACK){
            cout << "LIMIT REACHED" << endl;
        }
        arr[top] = a;
    }

    int pop(){
        if(top == -1){
            // no elements in the array
            cout << "NO ELEMENTS IN THE ARRAY" << endl;
            return -1;
        }
        int ele = arr[top];
        top--;
        return ele;
    }

    void popAll(){
        int t;
        while(top != -1){
            t = pop();
            cout << "POP: " << t <<  endl;
        }
    }
};


void main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.popAll();
}
```
    
Some key points regarding this code: 
+ In C++, we can use class instead of struct; and use private / public to hide / show the methods that we want to use
+ Pay close attention to how we are initialising the array
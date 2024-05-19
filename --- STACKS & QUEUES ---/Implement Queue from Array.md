Certainly! Here is the equivalent C++ code for implementing a queue using an array and the class structure provided. The queue allows elements to be added at the rear and removed from the front, maintaining a first-in, first-out (FIFO) order. 

```c++
#include <iostream>
using namespace std;

// Define the structure of the class
class MyQueue {
private:
    int arr[100005]; // Array to store queue elements
    int front;       // Index of the front element
    int rear;        // Index for the next element to be added

public:
    // Constructor to initialize the queue
    MyQueue() {
        front = 0;
        rear = 0;
    }

    // Function to push an element x into the queue
    void push(int x) {
        arr[rear++] = x;
    }

    // Function to pop an element from the queue and return that element
    int pop() {
        if (front == rear) {
            // The size of the queue is 0; the queue is empty
            return -1;
        }
        int first = arr[front];
        front++;
        return first;
    }
};

// Main function to test the queue implementation
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    // Trying to pop from an empty queue
    cout << "Popped: " << q.pop() << endl;

    return 0;
}
```

### Key Points:

1. **Class Definition**: The class `MyQueue` uses an array `arr` to store the queue elements, and two integer variables `front` and `rear` to manage the front and rear positions of the queue.
2. **Constructor**: Initializes `front` and `rear` to 0.
3. **Push Function**: Adds an element `x` to the rear of the queue and increments the `rear` index.
4. **Pop Function**: Removes an element from the front of the queue and returns it. If the queue is empty (i.e., `front == rear`), it returns -1.
5. **Main Function**: Demonstrates the functionality by pushing elements into the queue and then popping them, including a case where it attempts to pop from an empty queue.

This implementation ensures that the queue operates in a FIFO manner and handles cases where the queue is empty.
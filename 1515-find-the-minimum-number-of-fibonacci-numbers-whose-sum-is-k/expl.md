**Initial Idea**
- construct the fibonacci sequence & then pass it into the coin change problem

**The reason it got failed:**
- In the coin change problem, you have a case where `there is no solution`. Hence you are required to traverse all the possibilities for that question.
- But in this question, you need not check all, but rather, you can choose to go greedily because: `you have 1 in the coins array!`. So atleast if all solutions fail, then 1 comes to the rescue. `SOLUTION WILL EXIST in this question`
- so recursively keep subtracting the questions until you get to the 0 part.
- **so in a way, if the array contains 1, then the question can be solved greedily!!!**

```c++
class Solution {
public:
    void printV(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    int findMinFibonacciNumbers(int k) {
        // generate the fibonacci iteratively

        vector<int> fib;
        
        // base condition
        fib.push_back(1); // n = 1
        fib.push_back(1); // n = 2

        // generate until the last element is less than k
        int n = 2; // 2 elements in the array
        int last = 1;
        while(last <= k){
            int curr = fib[n - 1] + fib[n - 2];
            fib.push_back(curr);
            n++;
            last = curr;
        }

        // printV(fib);

        // the min number of coins would always be from the behind greedily
        // we know that solution definitely exists - SINCE IT IS FIBONACCI
        n = fib.size();
        int index = n - 1;

        int ans = 0;

        while(k != 0){
            while(k >= fib[index]){
                // remove the last element from the fibonacci continously
                k -= fib[index];
                ans++;
            }
            index--;
        }

        return ans;

    }
};
```

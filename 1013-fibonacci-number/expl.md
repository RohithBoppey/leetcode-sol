```c++
class Solution {
public:

    // complete recursive
    int fibR(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    // using 1D DP solutions 
    int fibDP(int n){
        if(n == 1 || n == 0){
            return n;
        }

        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int fib(int n){
        // return fibR(n);
        return fibDP(n);

    }

};
```

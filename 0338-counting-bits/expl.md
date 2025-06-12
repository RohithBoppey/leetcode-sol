Using Brain's algorithm: 
- the idea is to remove the right most set bit: `n & (n - 1)` --> remove the right most set bit
- do it until the n gets 0, in O(n), you will get the answer
  
```c++
class Solution {
public:
    int findOnes(int n){
        int count = 0;
        while(n != 0){
            count++;   // meaning we are removing the right most one bit
            n = n & (n - 1);
        }
        return count;
    }

    vector<int> countBits(int n) {
        // using Brain algorithm
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(findOnes(i));
        }
        return ans;
    }
};
```

DP solution (MY SOLUTION):
- logic is simple: for finding number of 1s in a number -> n % 2 + solve(n / 2)
- added memoization on top of it
- takes O(nlogn) complexity

```c++
class Solution {
public:
    vector<int> dp;

    int countOnes(int n){
        if(n <= 1){
            // 1 bit is there
            return n;
        }
        if(dp[n] != -1){
            // already present
            return dp[n];
        }
        
        // populate
        int rem = n % 2;
        return dp[n] = rem + countOnes(n / 2);
    }

    vector<int> countBits(int n) {
        dp.resize(n + 1, -1);
        dp[0] = 0;
        
        if(n > 0){
            dp[1] = 1;
        }

        for(int i = n; i >= 0; i--){
            if(dp[i] == -1){
                // solve it
                countOnes(i);
            }
        }

        return dp;
    }
};
```

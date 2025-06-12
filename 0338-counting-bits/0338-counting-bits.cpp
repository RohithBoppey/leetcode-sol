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
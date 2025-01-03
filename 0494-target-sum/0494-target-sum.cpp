class Solution {
public:

    int n;

    int solve(vector<int>& arr, int target, vector<vector<int>>& dp){
        
        // initialisation        
        // n == 0
        for(int i = 0; i <= target; i++){
            dp[0][i] = 0;
        }
        
        // target sum = 0 -> 1 subset exists
        // for(int i = 0; i <= n; i++){
        //     dp[i][0] = 1;
        // }
       
        dp[0][0] = 1;
        
        // processing
        int take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
             // can take or not take
             // take only when the current element is less than the limit
                take = (arr[i - 1] <= j) ? dp[i - 1][j - arr[i - 1]] : 0;
                notTake = dp[i - 1][j];
                
                // such sum can exist in both the cases, so +
                dp[i][j] = take + notTake;
                
            }
        }
        
        // print2d(dp);
        
        return dp[n][target];
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        n = nums.size();

        int sum = 0;
        for(auto &x: nums){
            sum += x;
        }

        target = abs(target);
        int t = sum + target;

        if(sum < target) return 0;
        if(t % 2) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(1001, 0));

        return solve(nums, t / 2, dp);
    }
};
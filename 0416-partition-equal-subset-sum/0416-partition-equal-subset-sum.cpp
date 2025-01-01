class Solution {
public:

    int n;

    bool solveRec(vector<int>& nums, int start, int target, vector<vector<int>>& dp){
        if(target == 0){
            // the selected subset exists
            return true;
        }

        if(start >= n){
            // cannot proceed further
            return false;
        }   

        if(dp[start][target] != -1){
            return dp[start][target];
        }

        // processing
        // can take or cannot take
        int take, notTake;

        // only take if my current val can fit in the bag
        take = (nums[start] <= target) ? solveRec(nums, start + 1, target - nums[start], dp) : false;
        notTake = solveRec(nums, start + 1, target, dp);

        return dp[start][target] = take || notTake; 
    }


    bool solveIter(vector<int>& nums, int target, vector<vector<int>>& dp){

        // initialisation the proper base cases
        for(int i = 0; i <= target; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        // now process
        int take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){

                // can take or not take
                take = (nums[i - 1] <= j) ? dp[i - 1][j - nums[i - 1]] : false;
                notTake = dp[i - 1][j];

                dp[i][j] = take || notTake;
            }
        }

        
        return dp[n][target];

    }

    bool canPartition(vector<int>& nums) {
        
        // lets solve using both the DP appraoches learnt
        // simply do sum / 2 and check whether the subset sum is feasible or not

        n = nums.size();
        
        int sum = 0;
        for(auto x: nums){
            sum += x;
        }
        if(sum % 2 == 1) return false; // cannot divide into 2 subsets of equal sum
        
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        // // 1. recursive solution
        // int start = 0;
        // // check whether such sum exists or not
        // return solveRec(nums, start, target, dp);


        // 2. Iterative Top Down solution
        return solveIter(nums, target, dp);

    }
};
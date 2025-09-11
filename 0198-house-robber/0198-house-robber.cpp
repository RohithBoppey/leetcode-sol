class Solution {
public:
    int rob(vector<int>& nums) {
        int n;
        n = nums.size(); 
        vector<int> dp(n + 1, 0); 

        if(n == 1){
            return nums[0];
        }

        dp[n - 1] = nums[n - 1];
        dp[n - 2] = max(nums[n - 1], nums[n - 2]);

        if(n == 2){
            return dp[n - 2];
        }

        for(int i = n - 3; i >= 0; i--){
            int rb, nrb; 
            rb = nums[i] + dp[i + 2];
            nrb = dp[i + 1];

            dp[i] = max(rb, nrb);
        }

        return dp[0];
    }
};
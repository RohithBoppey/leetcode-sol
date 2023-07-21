class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // from bottom to up
        
        int n = nums.size();
        
        vector<int> dp(n, 1);
        
        int mx = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    // then can be included
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;
        
    }
};
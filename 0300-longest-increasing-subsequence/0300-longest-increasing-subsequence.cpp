class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        // using dynamic programming
        vector<int> dp(n, 1);
        
        int mx = 1;
        
        // the base is 1
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                // compare and find
                if(nums[i] < nums[j]){
                    // that means j can be part of subsequence or not
                    dp[i] = max(dp[i], 1 + dp[j]);   
                }   
            }
            mx = max(mx, dp[i]);
        }
        
        // return the max
        return mx;
        
        
    }
};
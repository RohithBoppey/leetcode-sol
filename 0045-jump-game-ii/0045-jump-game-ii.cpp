class Solution {
public:
    
    int solve(int start, vector<int>& nums, vector<int>& dp, int& n){
        if(start >= n - 1){
            return 0;
        }
        
        if(dp[start] != 10001){
            return dp[start];
        }
        
        for(int i = 1; i <= nums[start]; i++){
            dp[start] = min(dp[start], 1 + solve(start + i, nums, dp, n));
        }
        
        return dp[start];
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        vector<int> dp(n, 10001);
        solve(0, nums, dp, n);
        return dp[0];
    }
};
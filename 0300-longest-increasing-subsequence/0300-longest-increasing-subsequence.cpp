class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        
        // base case is 1 because that can be included
        vector<int> dp(n, 1);
        
        int mx = 0; 
        
        // starting from behind
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                // comparing the right elements
                // can only be taken if it is greater
                
                // j > i
                
                if(nums[j] > nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                // else it is 1
                
                mx = max(mx, dp[i]);
            }
        }
        
        return mx;
    }
};
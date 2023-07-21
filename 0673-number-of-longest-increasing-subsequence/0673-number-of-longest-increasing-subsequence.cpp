class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        // using the same code as LIS from bottom up
        
        int n = nums.size();
        
        vector<int> dp(n, 1); // to store the max len
        vector<int> count(n, 1); // to store the freq of max len
        
        int mx = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                // compare and proceed
                if(nums[j] < nums[i]){
                    // we can take the element
                    if(dp[i] == dp[j] + 1){
                        // that means already some subsequence with the desired amount has been seen
                        // so add to the previous
                        count[i] += count[j];
                    }
                    
                    else if(dp[j] + 1 > dp[i]){
                        // we need to update the dp[i]
                        dp[i] = 1 + dp[j];
                        // add to the previous configuration
                        count[i] = count[j];
                        // update max
                        mx = max(mx, dp[i]);
                    }
                }
            }
        }
       
        int c = 0;
        
        // adding to the final result because the max count can be found wherever in the array
        
        for(int i = 0; i < n; i++){
            if(dp[i] == mx){
                c += count[i];
            }
        }
        
        return c;
        
    }
};
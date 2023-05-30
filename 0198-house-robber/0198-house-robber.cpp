class Solution {
public:
    int solve(vector<int>& nums, vector<int>& profit, int start, int n){
        if(start >= n){
            return 0;
        }
        if(profit[start] != -1){
            // already cal
            return profit[start];
        }
        
        // need to cal
        return profit[start] = max(
            nums[start] + solve(nums, profit, start + 2, n),
            solve(nums, profit, start + 1, n)
        );
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // start position is 0
        vector<int> profit(n + 1, -1);
        solve(nums, profit, 0, n);
        return profit[0];
    }
};
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    // check if such subset sum exists
    bool solve(vector<int>& nums, int s){
        dp.resize(n + 1, vector<int>(s + 1, 0));

        // initialization
        for(int i = 0; i < n; i++){
            // if sum = 0, possible
            dp[i][0] = 1;
        }

        // now for each, check if possible or not
        int can, cannot; 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= s; j++){
                // for each, can take or not cannot take
                can = (nums[i - 1] <= j) ? dp[i - 1][j - nums[i - 1]] : 0;
                cannot = dp[i - 1][j];

                // if either of that is true, take it
                dp[i][j] = can || cannot;
            }
        }
        
        return dp[n][s];
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size(); 

        int sum = 0;
        for(auto &x: nums){
            sum += x;
        }

        // check if exists
        return !(sum % 2) ? solve(nums, sum / 2) : false;
    }
};
class Solution {
public:

    void print2d(vector<vector<int>>& dp){
        for(auto &y: dp){
            for(auto &x: y){
                cout << x << " ";
            }
            cout << endl;
        }
    }

    bool checkIfSumExists(int sum, vector<vector<int>>& dp, vector<int>& nums, int n){
        // using tabulation 

        // init
        for(int i = 1; i <= n; i++){
            // when sum = 0, such arr is possible to construct
            dp[i][0] = 1;
        }

        // processing
        int can, cannot;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                // check can and cannot

                // take current element only when the capacity is left
                can = (nums[i - 1] <= j) ? dp[i - 1][j - nums[i - 1]] : 0;
                
                // if the element is not taken, sum wont change
                cannot = dp[i - 1][j];

                dp[i][j] = can || cannot;
            }
        }

        // print2d(dp);

        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // finding the sum of the array
        int sum = 0;
        for(auto& x: nums){
            sum += x;
        }

        vector<vector<int>> dp(n + 1, vector<int>((sum / 2) + 1));

        return (sum % 2) ? 0 : checkIfSumExists(sum / 2, dp, nums, n);
    }
};
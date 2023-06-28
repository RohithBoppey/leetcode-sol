class Solution {
public:
    int uniquePaths(int rows, int cols) {
        
        // initialising since everything is possible
        vector<vector<int>> dp(rows, vector<int>(cols, 1));
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                // processing based on both the ways possible
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[rows-1][cols-1];
    }
};

class Solution {
public:
    void print2d(vector<vector<int>>& dp){
        for(auto &x: dp){
            for(auto &y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }

    int uniquePaths(int m, int n) {
        // using memoization way
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // initialization
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }

        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }

        // processing
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // print2d(dp);

        return dp[m - 1][n - 1];
    }
};
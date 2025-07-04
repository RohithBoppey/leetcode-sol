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

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int flag = 1;
        for(int i = 0; i < n; i++){
            flag = (grid[0][i] == 1) ? 0 : flag;
            dp[0][i] = flag;
        }

        flag = 1;
        for(int i = 0; i < m; i++){
            flag = (grid[i][0] == 1) ? 0 : flag;
            dp[i][0] = flag;
        }

        // now process
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = (grid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // print2d(dp);

        return dp[m - 1][n - 1];

    }
};
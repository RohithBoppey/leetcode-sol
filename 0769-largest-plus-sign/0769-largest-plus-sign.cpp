class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        
        // Apply the mines
        for (auto &m : mines) {
            grid[m[0]][m[1]] = 0;
        }
        
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));
        
        // Compute left and up
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    left[i][j] = (j > 0 ? left[i][j - 1] : 0) + 1;
                    up[i][j] = (i > 0 ? up[i - 1][j] : 0) + 1;
                }
            }
        }
        
        // Compute right and down
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = (j < n - 1 ? right[i][j + 1] : 0) + 1;
                    down[i][j] = (i < n - 1 ? down[i + 1][j] : 0) + 1;
                }
            }
        }
        
        // Find the max order
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int arm_len = min({left[i][j], right[i][j], up[i][j], down[i][j]});
                    ans = max(ans, arm_len);
                }
            }
        }
        
        return ans;
    }
};

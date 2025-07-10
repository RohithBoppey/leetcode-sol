class Solution {
public:
    int rows, cols; 
    vector<vector<int>> vis; 
    int ans;

    int solve(vector<vector<int>>& grid, int row, int col){
        int area = 1;
        vis[row][col] = 1; 

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, 1, -1, 0};

        int nr, nc; 

        for(int i = 0; i < 4; i++){
            nr = row + dr[i];
            nc = col + dc[i];

            // check the new row
            if(nr < 0 || nc >= cols || nr >= rows || nc < 0 || grid[nr][nc] == 0){
                // invalid
                continue;
            }
            else{
                // the new value should be pakka pointing to land
                if(vis[nr][nc] == -1) { 
                    area += solve(grid, nr, nc);
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size(); 

        vis.resize(rows, vector<int>(cols, -1));

        ans = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(vis[i][j] == -1 && grid[i][j] == 1){
                    // island started, so do the dfs
                    // cout << i << j << endl;
                    int area = solve(grid, i, j);
                    ans = max(area, ans);
                }
            }
        }

        return ans; 
    }
};
class Solution {
public:

    int rows, cols; 
    vector<vector<int>> vis; 

    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vis.resize(rows, vector<int>(cols, -1));

        queue<vector<int>> q; 
        int ans = 0;

        // pushing all oranges into the queue
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, 1, -1, 0};

        while(!q.empty()){
            auto it = q.front();
            q.pop(); 

            int row = it[0];
            int col = it[1];
            int val = it[2];

            vis[row][col] = 1;

            ans = max(ans, val);

            int nr, nc;
            for(int i = 0; i < 4; i++){
                nr = row + dr[i];
                nc = col + dc[i];

                // check if in bounds or not
                if(nc >= 0 && nc < cols && nr >= 0 && nr < rows){
                    // valid
                    // but if unvisited, add to queue
                    if(vis[nr][nc] == -1 && grid[nr][nc] == 1){
                        // unvisited and unspoiled, so spoil in the next iteration
                        vis[nr][nc] = 1;
                        q.push({nr, nc, val + 1});
                    }
                }
            }

        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1){
                    // apple there and not visited
                    return -1;
                }
            }
        }

        return ans;     
    }
};
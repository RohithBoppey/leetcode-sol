class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int mx = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        
//         using BFS
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            
            vis[row][col] = 1;
            q.pop();
            mx = max(mx, step);
            
            for(int i = 0; i < 4; i++){
                int mrow = row + drow[i];
                int mcol = col + dcol[i];
                
//                 checking if the index is safe
                if(mrow >= 0 && mrow < rows && mcol >= 0 && mcol < cols){
//                     index is safe
//                     traverse -> widespread
                    if(grid[mrow][mcol] == 0 && !vis[mrow][mcol]){
                        q.push({{mrow, mcol}, step + 1});
                        vis[mrow][mcol] = 1;
                    }
                }
            }
            
//             check for -1 case
            // for(int i = 0; i < rows; i++){
            //     for(int j = 0; j < cols; j++){
            //         cout << vis[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
        
        return (mx == 0) ? -1 : mx;
    }
};
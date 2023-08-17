class Solution {
public:
    
    vector<int> drow{1, 0, -1, 0};
    vector<int> dcol{0, -1, 0, 1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> result(rows, vector<int>(cols, -1));
        
        // travel from 0 -> nearest 1
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    // that means it is 0 and push into q
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }
        
        
        // using bfs on 0 nodes and replacing with 1 nodes
        
        int r, c, nc, nr;
        
        while(!q.empty()){
            
            r = q.front().first;
            c = q.front().second;
            
            q.pop();
            
            // for each node, find neighbours and calc
            for(int i = 0; i < 4; i++){
                nr = r + drow[i];
                nc = c + dcol[i];
                
                // check if safe
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                    // safe
                    // check if already calc or need to calc
                    if(result[nr][nc] == -1){
                        // need to
                        // going from r,c -> nr,nc
                        result[nr][nc] = result[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        
        return result;
        
    }
};
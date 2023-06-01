class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // given n * n
        
        // start from 0,0 to n-1,n-1
        // traverse using 0s
        
        if(grid[0][0] == 1){
            // start position is 1, cannot traverse
            return -1;
        }
        
        // we can use bfs to solve this
        // bfs contains the time as well, if it meets, then that is max
        // if not, -1
        
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        queue<pair<pair<int,int>, int>> q;
        
        int maxCount = INT_MAX;
        q.push({{0,0}, 1});
        
        int row, col, mrow, mcol, c;
        
        while(!q.empty()){
            pair<pair<int,int>, int> top = q.front();
            q.pop();
            
            row = top.first.first;
            col = top.first.second;
            c = top.second;
            
            // cout << row << " " << col << " " << c << endl;
            
            visited[row][col] = 1;
            
            if(row == rows - 1 && col == cols - 1){
                // reached last index
                return c;
                maxCount = min(maxCount, c);
            }
            
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    mrow = row + i;
                    mcol = col + j;
                    
                    // check if mrow and mcol is valid
                    if(mrow >= 0 && mrow < rows && mcol >= 0 && mcol < cols){
                        // index is valid
                        if(visited[mrow][mcol] != 1 && grid[mrow][mcol] == 0){
                            // is valid and is 0 and not visited
                            visited[mrow][mcol] = 1;
                            q.push({{mrow, mcol}, c + 1});
                        }
                    }
                }
            }
        }
        
        return maxCount == INT_MAX ? -1 : maxCount;
    }
};
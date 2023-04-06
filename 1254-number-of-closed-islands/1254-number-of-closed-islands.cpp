class Solution {
public:
    
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};
    
    bool dfs(vector<vector<int>>& grid, int &row, int &col, vector<vector<int>>& visited, bool& status){
        int rows = grid.size();
        int cols = grid[0].size();
            
        // cout << row << " " <<  col << endl;
        
        visited[row][col] = 1;
        
        for(int i = 0; i < 4; i++){
            int mrow = row + drow[i];
            int mcol = col + dcol[i];
            
//             checking if the new index is safe or not
            if(mrow >= 0 && mrow < rows && mcol >= 0 && mcol < cols){
//                 now the index is safe
//                 if 0 we need to branch out
                if(grid[mrow][mcol] == 0 && !visited[mrow][mcol]){
//                     0 and unvisited
                    if(mrow == rows - 1 || mcol == cols - 1 || mrow == 0 || mcol == 0){
//                         reached the end, so return false
                       status = false;
                    }
                    
                    dfs(grid, mrow, mcol, visited, status);
                }
            }
            
        }
        
//         all checks passed can say it is a closed island
        return true;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
//         we are checking for only inner
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

//         initialisation done
        int count = 0;
        for(int i = 1; i < rows - 1; i++){
            for(int j = 1; j < cols - 1; j++){
                if(!visited[i][j] and grid[i][j] == 0){
                    bool status = true;
                    dfs(grid, i, j, visited, status);
                    if(status == true){
                        count++;
                    }
                    
                }
            }
        }      
        
        return count;
        
    }
};
- very similar to Rotten oranges (BFS) but the traversal is changed

```c++
class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<int> dr = {-2, -1, 1, 2, -2, 2, 1, -1};
        vector<int> dc = {1, 2, -2, -1, -1, 1, 2, -2};
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        // convert to 0-based indexing
        int sr = knightPos[0] - 1;
        int sc = knightPos[1] - 1;
        int tr = targetPos[0] - 1;
        int tc = targetPos[1] - 1;
        
        queue<array<int,3>> q; // r, c, steps
        q.push({sr, sc, 0});
        vis[sr][sc] = true;
        
        while(!q.empty()){
            // remove top element
            auto [r, c, steps] = q.front();
            q.pop(); 
            
            if(r == tr && c == tc){
                // guaranteed to return min
                return steps; 
            }
            
            // visit all unvisited neighbours
            for(int i = 0; i < 8; i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c; 
                
                // check if valid or not
                if(nr < n && nr >= 0 && nc < n && nc >= 0){
                    if(vis[nr][nc] == false){
                        // unvisited and valid, can add
                        vis[nr][nc] = true;
                        q.push({nr, nc, steps + 1});
                    }
                }
            }
        }
        
        return -1;
        
    }
};
```

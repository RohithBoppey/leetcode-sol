<img width="573" height="573" alt="image" src="https://github.com/user-attachments/assets/429ac0cf-b973-4601-856c-84f858f3e898" />

- the bruteforce approach would be: go to each node, do the DFS, and find out if from there, are we able to go to both atlantic and pacific oceans, then put it in our answer array
- but instead of that, what if we 2 take visited arrays and start from the atlantic ocean positions and pacific oceans positions (boundaries) and then see which nodes we can connect with
- here is the tricky part
- instead of normal DFS, we keep a prev pointer for the height seen, and only proceed based on the condition
- handling at the base condition, and blindly proceeding

```c++
class Solution {
public:

    void print2d(vector<vector<int>>& v){
        for(auto &x: v){
            for(auto &y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> vis, ans, pf, at;
    int rows, cols; 

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int row, int col, int prev){
        if(row < 0 || row >= rows || col < 0 || col >= cols){
            return;
        }

        if(visited[row][col] != -1){
            return;
        }

        // now check if the current value is higher than parent or not, only then we can flow
        int val = heights[row][col];
        if(val < prev){
            return;
        }

        visited[row][col] = 1;

        // now continue with dfs
        dfs(heights, visited, row + 1, col, val);
        dfs(heights, visited, row - 1, col, val);
        dfs(heights, visited, row, col + 1, val);
        dfs(heights, visited, row, col - 1, val);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        pf.resize(rows, vector<int>(cols, -1));
        at.resize(rows, vector<int>(cols, -1));

        for(int i = 0; i < rows; i++){
            // both atlantic and pacific
            dfs(heights, pf, i, 0, heights[i][0]);
            dfs(heights, at, i, cols - 1, heights[i][cols - 1]);
        }

        for(int i = 0; i < cols; i++){
            // both atlantic and pacific
            dfs(heights, pf, 0, i, heights[0][i]);
            dfs(heights, at, rows - 1, i, heights[rows -1][i]);
        }

        // print2d(pf);
        // cout << endl;
        // print2d(at);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(at[i][j] == 1 && pf[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans; 
    }
};
```

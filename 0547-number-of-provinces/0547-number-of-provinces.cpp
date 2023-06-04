class Solution {
public:
    void dfs(vector<vector<int>>& grid, int start, int n, vector<int>& vis){
        vis[start] = 1;
        
        for(int i = 0; i < grid[start].size(); i++){
            if(i != start && vis[i] != 1 && grid[start][i] == 1){
                dfs(grid, i, n, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // using dfs to solve this
        int n = isConnected.size();
        
        // n cities
        int count = 0;
        
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(isConnected, i, n, visited);
                count++;
            }    
        }
        
        return count;
    }
};
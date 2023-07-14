class Solution {
public:
    
    bool solve(int start, vector<int>& visited, vector<int>& in, vector<vector<int>>& adj){
        
        // using dfs
        visited[start] = 1;
        in[start] = 1;
        
        for(auto x: adj[start]){
            if(visited[x] == 0){
                // unvisited
                if(solve(x, visited, in, adj) == true){
                    // cycle in next calls
                    return true;
                }
            }else{
                // visited
                if(in[x] == 1){
                    return true;
                }
            }
        }
        
        
        in[start] = 0;
        return false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> ans;
        
        // using the same code as dfs in directed 
        // they will be marked as nodes unsafe
        
        int n = graph.size();
        
        vector<int> visited(n, 0);
        vector<int> in(n, 0);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                // unvisited
                solve(i, visited, in, graph);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                // they are not in the loop
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
    
};
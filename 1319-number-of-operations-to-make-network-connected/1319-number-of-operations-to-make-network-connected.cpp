class Solution {
public:
    void dfs(int start, vector<int>& visited, vector<vector<int>>& adjList){
        visited[start] = 1;
        for(auto x: adjList[start]){
            if(!visited[x]){
                dfs(x, visited, adjList);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size();
        if(sz < n - 1){
//             we require n - 1 edges to connect n nodes
//             cannot connect if number of edges are less than n - 1
            return -1;
        }
        
//         we need to find the number of isolated connected parts of the graph
        vector<int> visited(n, 0);
        
//         create adjList for the purpose
        vector<vector<int>> adjList(n);
        for(auto &x: connections){
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        
        int inde_size = 0;
        
//         finding the number of independent components
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                inde_size++;
                dfs(i, visited, adjList);
            }
        }
        
        
        // now we are having some k independent isolated components
        
        // applying the same logic, we require (k - 1) edges to connet these nodes
        
        // but how are we getting those nodes? From the extra ones from other components
        
        // we need not bother from where we are obtaining, just we can simply safely say we need (k - 1) edges to connect
        
        
        // This one failed for the final test case
        
        // return (inde_size == 1) ? 0: min(sz - inde_size, inde_size - 1);
        
        return inde_size - 1;
        
    }
};
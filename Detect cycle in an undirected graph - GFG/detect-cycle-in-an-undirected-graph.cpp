//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    
    bool solve(int start, vector<int>& visited, vector<int> adj[], int parent){
        visited[start] = 1;
        
        // check for all the children
        for(auto x: adj[start]){
            if(visited[x] == 0){
                // not visited
                if(solve(x, visited, adj, start) == true){
                    // cycle present in the subsequent nodes
                    return true;
                }
                
            }else{
                // visited
                // check for parent
                if(parent != x){
                    // cycle exists
                    return true;
                }
            }
        }
        
        return false;
        
    }
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        
        // solving using dfs
        
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                // unvisited
                    if(solve(i, visited, adj, -1) == true){
                    // cycle is present
                    return true;
                }    
            }
        }
        
        return false;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
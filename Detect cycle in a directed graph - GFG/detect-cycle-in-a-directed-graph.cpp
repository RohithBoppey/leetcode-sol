//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool solve(int start, vector<int>& visited, vector<int>& in, vector<int> adj[]){
        
        // using dfs to find the loop
        visited[start] = 1;
        in[start] = 1;
        
        for(auto x: adj[start]){
            // for all the nodes
            if(visited[x] == 0){
                // unvisited node
                if(solve(x, visited, in, adj) == true){
                    // found a loop in subsequent calls
                    return true;
                }
            }else{
                // is visited
                // check if it is visited in the current recursion call
                if(in[x] == 1){
                    // visited
                    // loop exisits
                    return true;
                }
            }
        }
        
        // removing from the current rec call
        in[start] = 0;
        return false;
        
    }
    
    
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        
        // to exist in a directed graph cycle
        // it has to be in the same recursion stack
        
        vector<int> visited(n, 0);
        vector<int> inRecursion(n, 0);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                // unvisited
                if(solve(i, visited, inRecursion, adj) == true){
                    // cycle exisits
                    return true;
                }
            }
        }
        
        // no cycle in all the components 
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
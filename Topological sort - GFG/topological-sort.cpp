//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfs(int start, vector<int>& visited, stack<int>& t, vector<int> adj[]){
	   visited[start] = 1;
	   for(auto node: adj[start]){
	       // first push the neighbours and then me
	       if(visited[node] == 0){
	           // unvisited
	           dfs(node, visited, t, adj);
	       }
	   }
	   t.push(start);
	}
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    
	    vector<int> visited(n, 0);
	    
	    stack<int> t; // to store the neighbours of each
	    
	    for(int i = 0; i < n; i++){
	        if(visited[i] == 0){
	            // unvisited
	            dfs(i, visited, t, adj);
	        }
	    }
	    
	    // pop and add to stack
	    int top;
	    int sz = t.size();
	    
	    while(sz != 0){
	        top = t.top();
	        t.pop();
	        ans.push_back(top);
	        sz--;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
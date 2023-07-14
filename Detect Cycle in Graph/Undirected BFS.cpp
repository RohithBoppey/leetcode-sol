class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool solve(int start, vector<int>& visited, vector<int> adj[]){
        
        queue<pair<int, int>> q;
        q.push({start, -1});
        
        // this q stores node and parent value
        
        while(!q.empty()){
            
            int node = q.front().first;
            int parent = q.front().second;
            
            visited[node] = 1;
            
            q.pop();
            
            for(auto x: adj[node]){
                if(visited[x] == 0){
                    // unvisited node, add to queue
                    q.push({x, node});
                    visited[x] = 1;
                }else{
                    // visited
                    // check for parent
                    if(x != parent){
                        // some other parent 
                        // loop exists
                        return true;
                    }
                }
            }
        }
        
        return false;
        
    }
    
    
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        
        // solving using bfs
        // storing as <node, parent>
        
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                // unvisited
                if(solve(i, visited, adj) == true){
                    // has a cycle
                    return true;
                }
            }
        }
        
        return false;
        
    }
};

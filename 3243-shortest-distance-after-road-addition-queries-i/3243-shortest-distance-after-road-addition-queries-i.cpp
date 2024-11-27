class Solution {
public:
    
    vector<vector<int>> adj;
    int len;
    
    int solve(int start, int end){
        
        // solve using BFS
        
        vector<int> dist(len, -1);
        
        // this queue contains the next paths that the graph will consider for the updation of the current path
        queue<int> q; 
        
        dist[start] = 0; // dist from 0 to 0 is 0
        
        q.push(start);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for (auto way: adj[curr]){
                // these are the ways that the graph can move further
                if(dist[way] == -1){
                    // untravesed path, so should traverse
                    dist[way] = dist[curr] + 1;
                    q.push(way);
                }
            }
        }
        
        return dist[end];
    }
    

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> ans;
        
        int start = 0;
        int end = n - 1;
        
        len = n;
        
        adj.resize(n, vector<int>());    
        // create adj
        for(int i = 0; i < n - 1; i++){
            adj[i].push_back(i + 1);
        }
        
        
        // update on the go
        int source, dest;
        for(auto &query: queries){
            source = query[0];
            dest = query[1];
            adj[source].push_back(dest);
            
            int dist = solve(start, end);
            ans.push_back(dist);
        }
        
        return ans;
        
    }
};
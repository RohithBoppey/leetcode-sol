class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        // solve using bfs
        
        // using the concept of topo sort
        vector<int> indegree(n, 0);
	    
	    for(int i = 0; i < n; i++){
	        for(auto x: adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    int countv = 0;
	    
	    for(int i = 0; i < n; i++){
	        if(indegree[i] == 0){
	            // they are the start nodes
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        countv++;
	        
	        // reduce 1 for all the neighbours
	        for(auto ne: adj[node]){
	            indegree[ne]--;
	            if(indegree[ne] == 0){
	                // that node is added now
	                q.push(ne);
	            }
	        }
	    }
	    
	    // check if all the nodes are visited or not
	    return (countv != n);
	    
    }
};
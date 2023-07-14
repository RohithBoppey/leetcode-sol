class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{   
	    // using solution of bfs
	    
	    // we need indegrees
	    vector<int> indegree(n, 0);
	    
	    for(int i = 0; i < n; i++){
	        for(auto x: adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i = 0; i < n; i++){
	        if(indegree[i] == 0){
	            // they are the start nodes
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        // reduce 1 for all the neighbours
	        for(auto ne: adj[node]){
	            indegree[ne]--;
	            if(indegree[ne] == 0){
	                // that node is added now
	                q.push(ne);
	            }
	        }
	    }
	    
	    return ans;
	}
};
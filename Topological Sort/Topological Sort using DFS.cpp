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
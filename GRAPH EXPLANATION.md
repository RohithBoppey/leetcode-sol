Simple Traversing Approach: 


DFS: 
[GFG Link](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
![image](https://github.com/user-attachments/assets/5ea96c7c-1aee-4965-8c2d-34b34e7aa3ef)

```c++
class Solution {
  public:
    
    vector<int> res;
    vector<int> visited;
    
    void dfs(vector<vector<int>>& adj, int start){
        // check whether the node is viisted or not
        if(visited[start] == 1){
            // already visited
            return;
        }
        
        // now visting it
        visited[start] = 1;
        res.push_back(start);
        
        // now visit the neighbours
        for(auto x: adj[start]){
            if(visited[x] == 0){
                // unvisited
                dfs(adj, x);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        
        int start = 0;
        int n = adj.size(); // int n = arr size
        
        // given adj directly
        visited.resize(n, 0);
        
        dfs(adj, start);
        
        return res;
        
        
    }
};

```

BFS solution: 
[GFG Link](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
![image](https://github.com/user-attachments/assets/ab8712ab-a706-4520-8be2-27302931e778)

```c++
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        
        int n = adj.size();
        
        // we use a queue for this approach
        vector<int> res;
        
        queue<int> q;
        vector<int> visited(n, 0);
        
        // adding the first start position
        int start = 0;
        q.push(start);
        visited[start] = 1;
        
        while(!q.empty()){
            
            int f = q.front();
            q.pop();
            
            res.push_back(f);
            
            // visiting the current node
            visited[f] = 1;
            
            // adding the neighbours
            for(auto x: adj[f]){
                if(visited[x] == 0){
                    // unvisited
                    visited[x] = 1;     // this step is need to ensure no duplication
                    q.push(x);
                    // res.push_back(x);
                }
            }
            
        }
        
        return res;
        
    }
};

```








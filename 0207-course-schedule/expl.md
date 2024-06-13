using the same logic as finding cycle exists in directed graph:
![WhatsApp Image 2023-07-14 at 16 52 42](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/dee24b03-1592-480f-a45f-a8099f47f77e)

```
class Solution {
public:
    
    bool solve(int start, vector<int>& visited, vector<int>& in, vector<vector<int>>& adj){
        
        // using dfs
        visited[start] = 1;
        in[start] = 1;
        
        for(auto x: adj[start]){
            if(visited[x] == 0){
                // unvisited
                if(solve(x, visited, in, adj) == true){
                    // cycle in next calls
                    return true;
                }
            }else{
                // visited
                if(in[x] == 1){
                    return true;
                }
            }
        }
        
        
        in[start] = 0;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // we can use the concept of bfs / dfs and if visited, then not possible
        // if all nodes are visited exactly once, then it is possible
        
        // construct adjList from the pre
        
        // pre is the list of edges
        
        vector<vector<int>> adjList(numCourses);
                
        for(auto &edge: prerequisites){
            // in order for [1,0] -> to complete 1, we need to complete 0
            // so direction from 0 to 1
            
            // adjList represents mapping from course->prereq, hence second->first
            adjList[edge[1]].push_back(edge[0]);
        }
        
        // there should not be any cycle
        
        vector<int> visited(numCourses, 0);
        vector<int> in(numCourses, 0); 
        
        for(int i = 0; i < numCourses; i++){
            if(solve(i, visited, in, adjList) == true){
                return false;
            }    
        }   
        
        return true;
        
        
    }
};
```​

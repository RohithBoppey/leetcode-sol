![WhatsApp Image 2023-07-14 at 14 01 32](https://user-images.githubusercontent.com/73538974/253518555-af8d1cc6-d002-4eb7-bac3-0bff1af5b566.jpg)

![image](https://user-images.githubusercontent.com/73538974/253516831-85b2650a-5109-43c6-9132-ee01cf5affe6.png)
![image](https://user-images.githubusercontent.com/73538974/253516863-8393d276-5bf6-49e6-94ef-ea6ef8d14608.png)
![image](https://user-images.githubusercontent.com/73538974/253516899-635811bc-d017-4e44-85aa-f5f3863490a9.png)
![image](https://user-images.githubusercontent.com/73538974/253516932-4e66ffb7-1cfa-4985-90f2-e5459cabc392.png)
![image](https://user-images.githubusercontent.com/73538974/253516963-0594791b-7d86-4ad0-a7dd-af9c39ea1a07.png)
      
DFS SOLUTION:   
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
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> ans;
        
        // using the same code as dfs in directed 
        // they will be marked as nodes unsafe
        
        int n = graph.size();
        
        vector<int> visited(n, 0);
        vector<int> in(n, 0);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                // unvisited
                solve(i, visited, in, graph);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                // they are not in the loop
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
    
};
```​

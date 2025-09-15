- basic DFS or BFS solution
- traversal method
- since we start from and find out which all rooms we can visit, but given an array of room keys
- so BFS can work

```c++
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        vis[0] = 1; // default

        queue<int> q;
        q.push(0); 

        while(!q.empty()){
            int t = q.front();
            q.pop(); 

            for(auto &neigh: rooms[t]){
                if(vis[neigh] == 0){
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        } 

        for(int i = 0; i < n; i++){
            // cout << vis[i] << " ";
            if(vis[i] == 0) return false; 
        }

        return true; 

    }
};
```

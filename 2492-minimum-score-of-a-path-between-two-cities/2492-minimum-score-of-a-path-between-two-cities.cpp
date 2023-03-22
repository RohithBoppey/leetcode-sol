class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
//         using bfs to solve the problem
//         the starting node is 1
//         we need to start from 1 and find which all nodes are connected
        
//         we need to create an adjList for the purpose
        vector<vector<int>> adjList(n + 1);
        for(auto &x: roads){
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        
        
//         now adjList is created
//         find which all can be visited from 1
        
        vector<int> visited(n + 1, 0);
        
        
//         using BFS - QUEUE
        
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = 1;
            
            for(int x: adjList[node]){
                if(!visited[x]){
                    q.push(x);
                }
                
            }
        }
        
        
//         we have updated the reachable terms from the 1
        
//         just traverse and find the least
        int ans = INT_MAX;
        for(auto &x: roads){
            if(visited[x[0]] == 1 && visited[x[1]] == 1 && x[2] < ans){
                ans = x[2];
            }
        }
        
    
        return ans;
    }
};






class Solution {
public:
    vector<vector<int>> adjList;
    long long totalFuel;
    
    long long dfs(int start, int parent, int& seats){
//         this functions is gonna give the number of the people coming towards the parent
//         based on that we will calculate the amount of fuel required
        
//         node contains already 1 people
        long long people = 1;
        for(auto node: adjList[start]){
            if(node != parent){
                people += dfs(node, start, seats);
            }
        }
        
//         all the people have been gathered
//         add to fuel only when the node is not equal to 0
        
        if(start != 0){
            int x = people / seats;
            if(people % seats != 0){
                x++;
            }
            totalFuel += x;
        }
        
        return people;
        
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        totalFuel = 0;
        int n = roads.size();
        if(n == 0){
            return 0;
        }
        adjList.resize(n + 1);
        for(auto &edge: roads){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, -1, seats);
        return totalFuel;
    }
};
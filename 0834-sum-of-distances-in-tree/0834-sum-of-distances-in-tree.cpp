class Solution {
public:
    
    /*
        REQUIRES PRE-REQUISITES:
        1. Finding the number of nodes for each node in a subtree
        2. Finding the distance of one node (easy)
    
    */
    
    
    void printVector(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    void initial_dfs(int node, int parent, int n, vector<vector<int>>& graph, int &dist, int height, vector<int>& subTreeLength) {
        // this function simultaneously calculates the distance for the root node
        // and also the length of each subtree 
        
        dist += height; // for each node matched, the distance gets added
        
        for(auto child: graph[node]){
            // for each node
            if(child != parent){
                initial_dfs(child, node, n, graph, dist, height + 1, subTreeLength);
                subTreeLength[node] += subTreeLength[child];
            }
        }
        
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // using the algorithm of Tree rerouting
        
        // initially we need to calculate the distance of the root node
        // and based on that we need to rework with the other distances
        
        // we can cal the total distance and subtree length of each node in a single DFS algorithm
        
        vector<int> distances(n, 0);
        vector<int> subTreeLength(n, 1); // each subtree has 1 length atleast
        
        // for that we need to create the DFS adjList
        vector<vector<int>> adjList(n);
        
        for(auto &edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        int dist = 0;
        initial_dfs(0, -1, n, adjList, dist, 0, subTreeLength);
        
        distances[0] = dist; 
        // we have calculated the distance
        
        // printVector(subTreeLength);
        
        // now that we have the subTreeLength and also the root distance
        // we can use the BFS or DFS from the root node to give us the distance using the subtree concept
        
        // using BFS
        
        queue<pair<int, int>> q; // {node, parent}
        q.push({0, -1});
        
        int node, parent;
        while(!q.empty()){
            node = q.front().first;
            parent = q.front().second;
                        
            if(parent != -1){
                // now the GIVEN FORMULA APPLIES
                distances[node] = distances[parent] - 2* (subTreeLength[node]) + n;
            }
            
            // now pushing and updating the other terms as needed
            for(auto child: adjList[node]){
                if(child != parent){
                    q.push({child, node});
                }
            }
            
            q.pop();
        }
            
        
        return distances;
    }
};
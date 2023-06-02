class Solution {
public:
    
    void print2dVector(vector<vector<int>> v){
        for(auto &x: v){
            for(auto &y: x){
                cout << y << " ";
            }
            cout << endl;
        }
        cout << "" << endl;
    }
    
    void printVector(vector<int> a){
        for(auto x : a){
            cout << x << " ";
        }
        cout << endl;
    }
    
    long long dis(int x1, int y1, int x2, int y2){
        return pow(x2-x1,2) + pow(y2-y1,2);
    }
    
    
    void dfs(int start, vector<vector<int>>& adjList, vector<int>& visited, int& len){
        len++;
        visited[start] = 1;
        for(auto x: adjList[start]){
            if(!visited[x]){
                // not visited neighbour
                dfs(x, adjList, visited, len);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        // detonate one bomb, return max number of bombs that denotate along with that
        // finding adj and then using bfs to solve
        int n = bombs.size();
        if(n == 1){
            // single bomb
            return 1;
        }
        
        vector<vector<int>> adjList(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // if the circles intersect, there is an edge
                if(i != j){
                    long long distance = dis(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]);
                    if(distance <= pow(bombs[i][2], 2)){
                        // is valid
                        adjList[i].push_back(j);
                    }
                    if(distance <= pow(bombs[j][2], 2)){
                        // is valid
                        adjList[j].push_back(i);
                    }
                }
            }
        }
        
        // print2dVector(adjList);
        
        int maxCount = 1;
        
        // dfs
        // should check for all
        
        
        for(int i = 0; i < n; i++){
            vector<int> visited(n, 0);
            // not visited
            int len = 0;
            dfs(i, adjList, visited, len);
            // once dfs is done
            maxCount = max(maxCount, len);
        }
        
        // printVector(visited);
        return maxCount;
    }
};
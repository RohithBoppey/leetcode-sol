class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int mx = 0;
        
        // require adjList
        vector<vector<int>> adjList(n);
        
        for(int i = 0; i < roads.size(); i++){
            adjList[roads[i][0]].push_back(roads[i][1]);
            adjList[roads[i][1]].push_back(roads[i][0]);
        }
        
        // adjList has been created
        // calc route sum for all routes
        
        int a, b, sum, t1, t2;
        vector<int> r1, r2;
        
        for(int i = 0 ; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                // if bond exists then +1 else + 2
                
                r1 = adjList[i];
                r2 = adjList[j];
                
                a = r1.size();
                b = r2.size();
                
                t1 = 0, t2 = 0;    
                
                // searching for j in r1
                while(t1 < a){
                    if(r1[t1] == j){
                        break;
                    }
                    t1++;
                }
                
                while(t2 < b){
                    if(r2[t2] == i){
                        break;
                    }
                    t2++;
                }
                
                if(t1 != a && t2 != b){
                    // means route exists
                    sum = a + b - 1;
                }
                
                else{
                    sum = a + b;
                }
                
                // since the bond to be calc only once
                mx = max(mx, sum);
            }
            
            
        }
        
        return mx;
        
    }
};
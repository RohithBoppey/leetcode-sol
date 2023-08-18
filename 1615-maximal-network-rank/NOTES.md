WIth the help of Observations:    
  1. We need to check for each pair of vertices -> i & j in n so O(N²) complexity.
  2. If there is a bond between i and j then the sum is degree - 1, because the bond should be considered as 1.
  3. Else there is no bond, we can direct add degree(i) + degree(j) = 1
  4. Find max among the degrees.
      
![WhatsApp Image 2023-08-18 at 10 34 30](https://user-images.githubusercontent.com/73538974/261506015-a435944e-0ec9-4875-9cda-259dce5cfdbe.jpg)
      
CODE:       
```
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
```

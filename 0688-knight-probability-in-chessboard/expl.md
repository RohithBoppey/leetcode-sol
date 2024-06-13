Probablity keeps on adding
      
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/9d20c53e-66a5-483f-b4df-1432d4b2659f)

```
class Solution {
public:
    
    unordered_map<string, double> mp;
    
    double solve(int n, int k, int row, int col, vector<int>& rowd, vector<int>& cold){
        
        // this function returns the corresponding probability of the consequent steps
        if(row < 0 || row >= n || col < 0 || col >= n){
            // not on the board;
            return 0;
        }
        
        if(k == 0){
            // reached the limit
            // must be on the board
            return 1.0;
        }
        
        // check if the call is already done
        string s = to_string(k) + "_" + to_string(row) + "_" + to_string(col);
        
        if(mp.find(s) != mp.end()){
            return mp[s];
        }
        
        double ans = 0.0;
        
        // since there are 8 directions to move in
        
        int nrow, ncol;
        
        for(int i = 0; i < 8; i++){
            nrow = row + rowd[i];    
            ncol = col + cold[i];
            
            // new rows probability has to be added
            ans += solve(n, k - 1, nrow, ncol, rowd, cold);            
        }
        
        return mp[s] = ans / 8.0;
        
    }
    
    double knightProbability(int n, int k, int row, int col) {
        
        if(k == 0){
            // no moves required
            return 1.0;
        }
        
        vector<int> rowd = {2, 2, -2, -2, 1, -1, 1, -1};
        vector<int> cold = {1, -1, 1, -1, 2, 2, -2, -2};
        
        return solve(n, k, row, col, rowd, cold);
        
    }
};
```

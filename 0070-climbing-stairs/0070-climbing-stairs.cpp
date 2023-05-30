class Solution {
public:
    
    int solve(vector<int>& res, int start, int n){
        if(start >= n){
            return 0;
        }
        
        if(res[start] != -1){
            // already done
            return res[start];
        }
        
        return res[start] = solve(res, start + 1, n) + solve(res, start + 2, n);
    }
    
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        
        vector<int> res(n + 1, -1);
        
        // initial
        res[n] = 0;
        res[n - 1] = 1;
        res[n - 2] = 2;
        
        return solve(res, 0, n);
    }
};
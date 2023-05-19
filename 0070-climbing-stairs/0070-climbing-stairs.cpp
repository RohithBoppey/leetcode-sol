class Solution {
public:
    int solve(vector<int>& ways, int n, int start){
        if(start >= n){
            // no way to reach the end
            return 0;
        }
        
        if(ways[start] != -1){
            // already calculated
            return ways[start];
        }
        
        // not cal
        // need to cal
        
        // it always depends on the next problem
        return ways[start] = solve(ways, n, start + 1) + solve(ways, n, start + 2); 
    }
    
    int climbStairs(int n) {
        // using the concept of DP
        vector<int> ways(n + 1, -1);
        
        if(n < 2){
            return 1;
        }
        
        ways[n] = 1;
        ways[n-1] = 1;
        ways[n-2] = 2;
        
        // ways means number of ways we can reach the end 
        // if the start position is i
        
        solve(ways, n, 0);
        return ways[0];
        
    }
};
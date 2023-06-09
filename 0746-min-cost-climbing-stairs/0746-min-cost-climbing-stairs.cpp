class Solution {
public:
    int solve(vector<int>& cost, int start, vector<int>& v, int n){
        if(start >= n){
            return 0;
        }
        
        if(v[start] != -1){
            return v[start];
        }
        
        // compute
        // either 1 step or 2 steps
        return v[start] = cost[start] + min(
            solve(cost, start + 1, v, n),
            solve(cost, start + 2, v, n)
        ); 
    
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // we need to reah the top
        
        // conditions:
        // 1. can start from index 0 or 1
        // 2. can move either 1 steps or 2
        
        // similar to climbing stairs but given cost for each operation
        
        // so we need to add a final cost to move to last one
        int n = cost.size();
        
        vector<int> v(n, -1);
        v.push_back(0);
        v[n-1] = cost[n-1];
        
        solve(cost, 0, v, n + 1);
        return min(v[0], v[1]);
    }
};




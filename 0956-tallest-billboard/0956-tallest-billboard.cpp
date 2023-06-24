class Solution {
public:
    int n;
    // the new dp is dp[index][diff] - max diss = -5000, so adding a threshold
    int dp[21][10003];
    
    int solve(vector<int>& rods, int curr, int diff){
        if(curr > n){
            return 0;
        }
        
        // new
        if(curr == n){
            if(diff == 0){
                return 0;
            }
            return INT_MIN;
        }
        
        if(dp[curr][diff + 5000] != -1){
            return dp[curr][diff + 5000];
        }
        
        
        // we can take or not take
        int take1 = rods[curr] + solve(rods, curr + 1, diff + rods[curr]);
        int take2 = rods[curr] + solve(rods, curr + 1, diff - rods[curr]);
        int nottake = solve(rods, curr + 1, diff);
        
        return dp[curr][diff + 5000] = max({take1, take2, nottake});
        
    }
    
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        memset(dp, -1, sizeof(dp));
        // initial diff is 0
        return solve(rods, 0, 0) / 2;
    }
};
class Solution {
public:
    int n;

    int solve(vector<int>& jd, int d, vector<vector<int>>& dp, int start){
        // base case
        int mx = INT_MIN;
        
        if(dp[start][d] != -1){
            // already calc
            // cout << "al" << endl;
            return dp[start][d];
        }
        
        if(d == 1){
            // find max to the right & return
            for(int i = start; i < n; i++){
                mx = max(mx, jd[i]);
            }
            return dp[start][d] = mx;
        }

        int mn = INT_MAX;

        // we need to solve
        for(int i = start; i <= n - d; i++){
            // first we need to find the running max
            mx = max(mx, jd[i]);
            // and the next cut which can give me minimum sum
            // max_num so far + subsequent_min_cut will give us the answer
            mn = min(mn, mx + solve(jd, d - 1, dp, i + 1));
        }

        return dp[start][d] = mn;
    }

    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();

        if(n < d){
            // days are more, tasks less
            // some day can be with no task
            return -1;
        }

        // dp[index][days] -> table for what is the min value starting at this index and having x days left
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        solve(jd, d, dp, 0);

        // dp[0][d] -> means starting at index 0, having d days left
        return dp[0][d];

    }
};
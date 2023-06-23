class Solution {
public:
    
    int dp[5001][2];
    
    int max1(int a, int b, int c){
        return max(a, max(b, c));
    }
    
    int solve(vector<int>& prices, int day, bool buy, int &n){
        // this function return max profit that can be obtained from day 0
        if(day >= n){
            // cannot generate any profit
            return 0;
        }
        
        if(dp[day][buy] != -1){
            // already sol
            return dp[day][buy];
        }
        
        int profit = 0;
        
        if(buy == true){
            // if buying he is spending amount, so whaterver profit he gets below, he needs to subtract current
            int buy = solve(prices, day + 1, false, n) - prices[day];
            int notbuy = solve(prices, day + 1, true, n);
            profit = max1(profit, buy, notbuy);
        }
        else{
            // he can sell or not sell
            // cooldown exists, so +2;
            int sell = solve(prices, day + 2, true, n) + prices[day];
            int notsell = solve(prices, day + 1, false, n);
            profit = max1(profit, sell, notsell);
        }
        
        return dp[day][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true, n);
    }
};
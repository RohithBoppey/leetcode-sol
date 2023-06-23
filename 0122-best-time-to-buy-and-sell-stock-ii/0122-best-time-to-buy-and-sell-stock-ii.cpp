class Solution {
public:
    
    int dp[30001][2];
    
    int solve(vector<int>& prices, int day, bool buy, int &n){
        // this function will return max profit that can be obtained starting from day 
        if(day >= n){
            // cannot generate
            return 0;
        }
        
        if(dp[day][buy] != -1){
            // already cal
            return dp[day][buy];
        }
        
        // need to cal
        
        int profit = 0;
        
        if(buy == true){
            // he can either buy or not
            // if buying, he is spending money, so profit - currentAmount
            int buy = solve(prices, day + 1, false, n) - prices[day];
            int notbuy = solve(prices, day + 1, true, n);
            profit = max({profit, buy, notbuy});
            
        }else{
            // he can sell or nto
            // if selling, he gets the money + next profit
            int sell = solve(prices, day + 1, true, n) + prices[day];
            int notsell = solve(prices, day + 1, false, n);
            profit = max({sell, notsell, profit});
        }
        
        return dp[day][buy] = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true, n);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> free(prices.size()),hold(prices.size());

        // buying stock on day 1
        hold[0] = -prices[0];
        for(int i = 1;i < prices.size();i++){
            // Buying stock today or not doing anything.
            hold[i] = max(hold[i-1],free[i-1]-prices[i]);
            // Selling stock today or not doing anything.
            free[i] = max(free[i-1],hold[i-1]+prices[i]-fee);
        }
        return free[prices.size()-1];
    }
};
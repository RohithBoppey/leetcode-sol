class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 

        vector<int> sell(n, 0);

        int mx = 0;
        sell[n - 1] = prices[n - 1];

        // now populate the sell array based on the max amount you can sell
        for(int i = n - 2; i >= 0; i--){
            sell[i] = max(sell[i + 1], prices[i]);
            mx = max(mx, sell[i] - prices[i]);
        }

        return mx;
    }
};
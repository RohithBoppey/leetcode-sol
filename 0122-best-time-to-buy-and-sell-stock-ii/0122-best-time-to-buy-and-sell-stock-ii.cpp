class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // greedy would work here
        int n = prices.size();
        int profit = 0;

        for(int i = 1; i < n; i++){
            profit += (prices[i] > prices[i - 1]) ? prices[i] - prices[i - 1] : 0;
        }

        return profit; 
    }
};
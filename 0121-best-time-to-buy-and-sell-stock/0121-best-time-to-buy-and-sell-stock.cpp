class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int local_max = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            local_max = max(local_max, prices[i]);
            if(local_max != INT_MIN){
                ans = max(ans, local_max - prices[i]);
            }
        }
        return ans;
    }
};
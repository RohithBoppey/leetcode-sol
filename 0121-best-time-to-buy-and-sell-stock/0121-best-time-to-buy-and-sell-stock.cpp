class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int mx = -1;
        
        int p, mp = 0;
        
        // the idea is to find the max number possible (SO FAR)
        for(int i = n - 1; i >= 0; i--){
            if(mx == -1){
                mx = prices[i];
            }else{
                // not empty
                if(mx > prices[i]){
                    // bigger price
                    p = mx - prices[i];
                    mp = max(p, mp);
                }else{
                    // smaller price
                    mx = prices[i];
                }
            }         
        }
        
        return mp;
    }
};



class Solution {
public:
    void printVector(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0){
            return 0;
        }
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
       
        sort(coins.begin(), coins.end());
        
        // populating the dp array
        for(int i = 1; i <= amount; i++){
            for(auto c: coins){
                if(i - c < 0){
                    // cannot proceed
                    break;
                }
                
                // can work
                if(dp[i - c] != INT_MAX){
                    // already done
                    dp[i] = min(1 + dp[i - c], dp[i]);
                }
            }
        }
        
        // printVector(dp);
        
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
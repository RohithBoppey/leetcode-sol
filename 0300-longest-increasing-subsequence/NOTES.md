Kind of 1D Dynamic Programming, but twisted slightly, a little bit hard intuition!            
                  
![WhatsApp Image 2023-07-21 at 14 00 07](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/f4cbf95f-c52f-41ec-8051-1f0b1030d507)      
![WhatsApp Image 2023-07-21 at 14 00 06](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/467c4ab5-9716-487c-b4a5-638f7297056d)      
      
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        // using dynamic programming
        vector<int> dp(n, 1);
        
        int mx = 1;
        
        // the base is 1
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                // compare and find
                if(nums[i] < nums[j]){
                    // that means j can be part of subsequence or not
                    dp[i] = max(dp[i], 1 + dp[j]);   
                }   
            }
            mx = max(mx, dp[i]);
        }
        
        // return the max
        return mx;
        
        
    }
};

```                  
                  
There is another varaint for this (BOTTOM UP APPROACH): Not much difference, changing in the loops                  
                  
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // from bottom to up
        
        int n = nums.size();
        
        vector<int> dp(n, 1);
        
        int mx = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    // then can be included
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;
        
    }
};
```

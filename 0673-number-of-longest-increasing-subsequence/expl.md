Using the bottom up approach for this problem.    
      
1. If finding for the first time, we will not update the count.     
2. Next time, since the number is added to all of that of previous, count[curr] += count[prev]    
        
![WhatsApp Image 2023-07-21 at 14 38 24](https://user-images.githubusercontent.com/73538974/255133774-c1d116d2-306c-4a44-9108-98573830c748.jpg)     
              
DRY RUN:      
      
![image](https://user-images.githubusercontent.com/73538974/255133711-73703c41-94c7-468a-95f0-6497c3f2eaf5.png)     
![image](https://user-images.githubusercontent.com/73538974/255133886-af603a44-8e9a-40e9-93df-910a4093d713.png)   
![image](https://user-images.githubusercontent.com/73538974/255133904-2dd32bdf-cae2-4c82-8055-526fcee46536.png)     
![image](https://user-images.githubusercontent.com/73538974/255134047-75bf3de5-8503-45e5-9d95-a6a4624979a8.png)
![image](https://user-images.githubusercontent.com/73538974/255134077-daabf172-9bbe-45bf-8690-6cd4fd10ca06.png)

```
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        // using the same code as LIS from bottom up
        
        int n = nums.size();
        
        vector<int> dp(n, 1); // to store the max len
        vector<int> count(n, 1); // to store the freq of max len
        
        int mx = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                // compare and proceed
                if(nums[j] < nums[i]){
                    // we can take the element
                    if(dp[i] == dp[j] + 1){
                        // that means already some subsequence with the desired amount has been seen
                        // so add to the previous
                        count[i] += count[j];
                    }
                    
                    else if(dp[j] + 1 > dp[i]){
                        // we need to update the dp[i]
                        dp[i] = 1 + dp[j];
                        // add to the previous configuration
                        count[i] = count[j];
                        // update max
                        mx = max(mx, dp[i]);
                    }
                }
            }
        }
       
        int c = 0;
        
        // adding to the final result because the max count can be found wherever in the array
        
        for(int i = 0; i < n; i++){
            if(dp[i] == mx){
                c += count[i];
            }
        }
        
        return c;
        
    }
};
```​

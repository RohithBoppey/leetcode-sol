​This code is failing for the test case: `[8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309]
134365`.       
This code is of DP Approach.
      
![image](https://user-images.githubusercontent.com/73538974/269237055-0f1a588a-005a-45bf-b451-548c04828e14.png)
      
```
class Solution {
public:
    
    void solve(vector<int>& nums, int n, int x, int& ans, int steps, int left, int right){
        // base condition
        if(left > right){
            return;
        }
        
        if(x < 0){
            // cant proceed
            return;
        }
        
        if(x == 0){
            ans = min(ans, steps);
            return;
        }
        
        // can take from left or right
        
        // left
        solve(nums, n, x - nums[left], ans, steps + 1, left + 1, right);
        solve(nums, n, x - nums[right], ans, steps + 1, left, right - 1);
        
        return;
        
    }
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        // can take left or right
        int ans = INT_MAX;
        int steps = 0;
        
        solve(nums, n, x, ans, steps, 0, n - 1);
        
        return ans == INT_MAX ? -1 : ans;
        
    }
};
```
      
Probably, one edge case might be missing.
    
The idea is to find the max subarray of (totalSum - x), and remove the remaining number of elements.    
    
Need some reverse thinking....    
      
![image](https://user-images.githubusercontent.com/73538974/269249315-abdaf6ed-6541-4b94-a61e-fac8422d9588.png)
![image](https://user-images.githubusercontent.com/73538974/269249360-1ccfa7b6-03f5-4650-892f-a2e71eb6c47e.png)
![image](https://user-images.githubusercontent.com/73538974/269249395-3c760ba1-d1bb-4f3e-b112-48e1e9ff3d30.png)
      
CODE:   
```
class Solution {
public:
    
    // this function will return the minLength of the subarray, which equates to the sum
    int solve(vector<int>& v, int sum){
        int n = v.size();
        int mn = 0;

        int i = 0, j = 0;
        int csum = 0;

        while(j < n){
            csum += v[j];

            if(csum > sum){
                // reduce until less
                while(i < j && csum > sum){
                    csum -= v[i];
                    i++;
                }
            }


            if(csum == sum){
                // find min
                mn = max(mn, j - i + 1);
            }

            j++;

        }

        return mn;
    }
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        // find totalSum;
        int totalSum = 0;
        
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        
        if(totalSum == x){
            // all has to be considered
            return n;
        }
        
        // find maxSubarray with sum - x len
        int sum = totalSum - x;
        
        int len = solve(nums, sum);
        
        // cout << len << endl;
        
        if(len == 0){
            // no subarray found
            return -1;
        }
        
        return n - len;
        
    }
};
```
      


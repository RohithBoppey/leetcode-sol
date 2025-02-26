![WhatsApp Image 2025-02-26 at 10 29 03_dc9f2cbf](https://github.com/user-attachments/assets/47b64838-c8a4-454e-aacf-1141d4be329f)

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using Kadence's algorithm to find the max subarray sum
        int n = nums.size();
        int csum = nums[0], mx = nums[0];
        
        // kadence - the question is: Is it better to start a new subarray from this position or is it better to append to the already formed subarray 
        for(int i = 1; i < n; i++){
            csum = max(nums[i], csum + nums[i]);
            mx = max(csum, mx);
        }

        return mx;
    }
};
```​

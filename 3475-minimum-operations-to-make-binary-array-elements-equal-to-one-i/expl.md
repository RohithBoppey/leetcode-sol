Uses the same bruteforce code from: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/ (Check solution for this as well)

```c++
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();

        // add another array for the count of flips for each
        vector<int> flips(n, 0);
        int tf = 0; //total flips

        int i = 0;
        while(i < n){
            // check and do the flip
            if(
                (nums[i] == 0 && flips[i] % 2 == 1) 
                || 
                (nums[i] == 1 && flips[i] % 2 == 0)
            ){
                // no need of flipping
                i++;
            }else{
                // we need to flip the k-size window
                int t = k, j = i;

                // boundary condition
                if(i > n - k){
                    // cannot proceed further
                    return -1;
                }

                tf++;
                while(t != 0){
                    flips[j]++;
                    j++;
                    t--;
                }
                i++;
            }
        }

        return tf;

    }

    int minOperations(vector<int>& nums) {
        return minKBitFlips(nums, 3);
    }
};
```

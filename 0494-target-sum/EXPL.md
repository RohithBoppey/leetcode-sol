Simple bruteforce problem approach: 

```c++
class Solution {
public:
    int ans;
    int n;

    void solve(vector<int>& nums, int target, int start, int curr){
        // cout << start << " " << curr << endl;
        
        if(curr == target && start == n){
            ans++;
        }

        if(start >= n){
            // cannot move further
            return;
        }
        

        // every position can have + or - before the number
        // if(nums[start] == 0){
        //     // can skip the number
        //     solve(nums, target, start + 1, curr);
        //     return;
        // }
        solve(nums, target, start + 1, curr + nums[start]);
        solve(nums, target, start + 1, curr - nums[start]);

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        ans = 0;
        solve(nums, target, 0, 0);
        return ans;
    }
};
```
But optimised solution uses the concept of DP + Memoization -> Can find it in [DYNAMIC PROGRAMMING ENTIRE EXPLANATION.md](https://github.com/RohithBoppey/leetcode-sol/blob/master/DYNAMIC%20PROGRAMMING%20ENTIRE%20EXPLANATION.md)

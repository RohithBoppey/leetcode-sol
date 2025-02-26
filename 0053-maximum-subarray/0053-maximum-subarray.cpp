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
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int csum = nums[0], msum = nums[0];
        for(int i = 1; i < n; i++){
            csum = max(csum + nums[i], nums[i]);
            msum = max(msum, csum);
        }
        return msum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int s1, s2;
        s1 = maxSubArray(nums);
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] *= -1;
        }
        s2 = maxSubArray(nums);
        return max(s1, s2);
    }
};
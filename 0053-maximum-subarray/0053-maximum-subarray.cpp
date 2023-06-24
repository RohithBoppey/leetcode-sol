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
};
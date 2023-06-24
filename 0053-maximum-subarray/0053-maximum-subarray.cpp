class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int csum = 0, msum = nums[0];
        for(int i = 0; i < n; i++){
            csum += nums[i];
            msum = max(msum, csum);
            csum = (csum < 0) ? 0 : csum; 
        }
        return msum;
    }
};
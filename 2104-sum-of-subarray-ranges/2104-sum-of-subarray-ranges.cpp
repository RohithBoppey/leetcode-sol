class Solution {
public:
    
    int n;
    int ms = INT_MIN, mn = INT_MAX;
    
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        n = nums.size();
        for(int i = 0; i < n; i++){
            ms = nums[i];
            mn = nums[i];
            for(int j = i; j < n; j++){
                ms = max(ms, nums[j]);
                mn = min(mn, nums[j]);
                ans += (ms - mn);
            }
        }
        return ans;
    }
};
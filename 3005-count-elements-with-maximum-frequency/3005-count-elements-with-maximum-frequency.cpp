class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(101, 0);
        int mx = 0;
        for(int i = 0; i < n; i++){
            f[nums[i]]++;
            mx = max(mx, f[nums[i]]);
        }
        int ans = 0;
        for(int i = 0; i < 101; i++){
            if(f[i] == mx){
                ans += mx;
            }
        }
        return ans;
    }
};
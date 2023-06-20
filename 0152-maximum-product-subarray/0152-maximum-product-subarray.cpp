class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN, prefix = 1, suffix = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            
            mx = max(mx, max(prefix, suffix));
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
        }
        return mx; 
    }
};
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        
        int ll = 0, rr = 0, lr = 0;
        
        // total of 3 possibilites possible
        sort(nums.begin(), nums.end());
        
        // changing both the left first 2 terms to be the same as the third term -> min is 0, max would be last - 3rd
        ll = nums[n - 1] - nums[2];
        
        // changing both right last 2 terms to be the same as the (n-3)rd term, that way min = 0 and max woudl be (n-3) - first number
        rr = nums[n - 3] - nums[0];
        
        // changing first term as second and last term as (n-2)nd, that way -> min = 0, but max = (n-2)nd - 2nd term
        lr = nums[n - 2] - nums[1];
        
        ans = min(min(ll, rr), lr);
        
        return ans;
    }
};
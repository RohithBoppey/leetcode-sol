class Solution {
public:
    int n;
    int ans;

    void solve(vector<int>& nums, int start, int curr){
        if(start >= n){
            // reached the end
            ans += curr;
            return;
        }

        // for each, we can take or not take
        solve(nums, start + 1, curr);
        solve(nums, start + 1, curr ^ nums[start]);
    }

    int subsetXORSum(vector<int>& nums) {
        n = nums.size(); 
        ans = 0;
        int curr = 0;

        solve(nums, 0, curr);

        return ans; 
    }
};
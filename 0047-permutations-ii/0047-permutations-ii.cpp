class Solution {
public:
    void solve(vector<int>& nums, int start, set<vector<int>>& res, int &n){
        if(start == n - 1){
            res.insert(nums);
            return;
        }
        
        solve(nums, start + 1, res, n);
        for(int i = start + 1; i < n; i++){
            if(nums[start] != nums[i]){
                swap(nums[i], nums[start]);
                solve(nums, start + 1, res, n);
                swap(nums[i], nums[start]);
            }
        }
        
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        solve(nums, 0, res, n);
        vector<vector<int>> ans;
        for(auto x: res){
            ans.push_back(x);
        }
        return ans;
    }
};
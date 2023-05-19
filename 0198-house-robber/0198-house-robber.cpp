class Solution {
public:
    int solve(vector<int>& nums, vector<int>& profit, int start, int &n){
        if(start >= n){
            return 0;
        }
        
        if(profit[start] != -1){
            return profit[start];
        }
        
        // calc now
        // if rob -> start + 2
        // no rob -> start + 1
        return profit[start] = max(
            solve(nums, profit, start + 1, n),
            nums[start] + solve(nums, profit, start + 2, n)
        );
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            // only house and hence rob that
            return nums[0];
        }
        vector<int> profit(n + 1, -1);
        solve(nums, profit, 0, n);
        for(auto x: profit){
            cout << x << " ";
        }
        cout << endl;
        return profit[0];
    }
};
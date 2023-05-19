class Solution {
public:
    int solve(vector<int>& nums, int start, int &n, vector<int>& profit){   
        if(start >= n){
            // the amount he can rob starting from start is 0
            // coz there are no houses
            return 0;
        }    
        
        if(profit[start] != -1){
            // already calculated
            return profit[start];
        }
        
        // now he can either take or not take
        return profit[start] = max(
            nums[start] + solve(nums, start + 2, n, profit),
            solve(nums, start + 1, n, profit)
        );
    }
    
    int HouseRob(vector<int>& nums) {
        // 1D dynamic programming
        // profit[i] shows max profit starting from pos i
        
        int n = nums.size();
        if(n == 1){
            // can only rob that house
            return nums[0];
        }
        
        // start from 0 and find
        vector<int> profit(n, -1);
        return solve(nums, 0, n, profit);
    }
    
    int rob(vector<int>& nums) {
        // given there is a circle
        // first and last one are adjacent
        
        // so should either be in 0 to n -1 
        // or 1 to n
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        vector<int> firstSet(nums.begin(), nums.end() - 1);
        vector<int> secondSet(nums.begin() + 1, nums.end());
        
        return max(
            HouseRob(firstSet),
            HouseRob(secondSet)
        );
    }
};



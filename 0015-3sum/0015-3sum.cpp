class Solution {
public:
    
    
    void solve(vector<int>& nums, vector<vector<int>>& result, int n, int target){
        
        // this function populates the result array with the ones whose sum is 0
        
        int fix; // index that we are fixing
        int low, high; // index through which we traverse
        
        long long int sum;
        
        vector<int> ans(3, 0);
        
        for(int i = 0; i < n - 2; i++){
            
            // ensuring that i is also not repeating
            if(i != 0 && nums[i] == nums[i - 1]){
                // not unique
                continue;
            }
            
            fix = i;
            low = i + 1;
            high = n - 1;
            
            // finding based on index;
            // modify low and high
            
            while(low < high){
                sum = nums[low] + nums[fix] + nums[high];
                if(sum == (long long int) target){
                    // we found it
                    ans[0] = nums[low];
                    ans[1] = nums[fix];
                    ans[2] = nums[high];
                    
                    result.push_back(ans);
                    ans.resize(3, 0);
                    
                    // move to positions which are not repeating
                    
                    while(low < high && nums[low] == nums[low + 1])   low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;
                    
                    low++;
                    high--;
                }
                
                else if(sum < target){
                    low++;
                }
                
                else{
                    high--;
                }
            }
            
        }
        
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // we need to sort the array 
        // for that to be low or high
        
        int n = nums.size();
        
        vector<vector<int>> result;
        
        sort(begin(nums), end(nums));
        
        solve(nums, result, n, 0);
        
        return result;
        
    }
};
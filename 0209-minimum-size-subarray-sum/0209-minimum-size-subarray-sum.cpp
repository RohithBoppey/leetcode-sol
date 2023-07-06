class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        
        int sum = 0;
        
        int i = 0, j = 0, sz = 0;
        
        while(j < n){
            
            sum += nums[j];
            
            if(sum >= target){
                
                // reduce from behind
                
                while(sum >= target){
                    sz = j - i + 1;
                    ans = min(ans, sz);
                    sum -= nums[i];
                    i++;
                }
                
                j++;
                
            }
            else if(sum < target){
                
                j++;
            }
            
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};
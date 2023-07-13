class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // using the concept of sliding window
        
        int n = nums.size();
        
        int i = 0, j = 0;
        
        int ans = 0;
        
        while(j < n){
            
            if(nums[j] == 1){
                j++;
            }
            else {
                
                // it is not 1
                // find max size of 1s and compare
                ans = max(ans, j - i);
                
                // find the next 1
                while(j < n && nums[j] != 1) {j++;}
                i = j;    
            }
        }
        
        if(i != n){
            // last set of 1 are still there
            ans = max(ans, j - i);
        }
        
        return ans;
        
    }
};
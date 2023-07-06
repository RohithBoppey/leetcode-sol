class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // this is not optimal approach, just better approach
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        // sorting to find the sequence
        sort(nums.begin(), nums.end());
        
        int count = 1, last_ele = nums[0], maxCount = 1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] == last_ele + 1){
                // it is in a sequence
                count++;
                last_ele = nums[i];
            }else if(nums[i] == last_ele){
                // do nothing
            }else{
                // reset the counter
                count = 1;
                last_ele = nums[i];
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
        
    }
};
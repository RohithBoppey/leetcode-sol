class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        // map
        unordered_map<int, int> mp;
        
        // hash the target - nums[i]
        
        for(int i = 0; i < n; i++){
            
            if(mp.find(target - nums[i]) != mp.end()){
                // found
                return {i, mp[target - nums[i]]};
            }
            
            mp[nums[i]] = i;
            
        }
        
        
        return {-1, -1};
    }
};
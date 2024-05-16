class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // idea is to find number of distinct number of elements in the subarray
        
        int dis = 0, len = 0;
        int i = 0, j = 0;
        int n = nums.size();
        int req = 0; // this is the required count of numbers in the subarray to make it a good subarray => distinct * k
        int ans = 0;
        
        // if 
        
        unordered_map<int,int> mp;
        
        while(j < n){
            if(mp.find(nums[j]) == mp.end()){
                // not present in map
                // unique element
                dis++;
            }
            
            mp[nums[j]]++;
            len = j - i + 1;
            
            // we need to compare with the required count
            req = dis * k;
            
            while(len > req || mp[nums[j]] > k){
                // we need to remove from back until is falls back under the range
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    // remove the element
                    mp.erase(nums[i]);
                    dis--;
                }
                i++;
                
                len = j - i + 1;
                req = dis * k;
            }
            
            // that means len < max req
            // this must be a good subarray
            
            ans = max(ans, len);
            j++;
        }
        
        return ans;
    }
};
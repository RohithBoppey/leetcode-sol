class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numberOfSubarrays = 0;
        int n = nums.size();
        int curr = 0, toCheck;
        
        unordered_map<int, int> mp; // contains a map of <prefixSum, count>
        
        mp[0] = 1; // to remove nothing
        
        for(int i = 0; i < n; i++){
            curr += nums[i];
            toCheck = curr - k;
            numberOfSubarrays += mp[toCheck];
            mp[curr]++;
        }
        
        return numberOfSubarrays;
    }
};
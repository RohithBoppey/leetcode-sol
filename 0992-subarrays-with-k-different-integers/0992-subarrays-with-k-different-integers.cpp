class Solution {
public:
    
    int slidingWindow(vector<int>& nums, int k){
        // even if k == 1 there could be case like [1,2,1,1,1,1,3]
        
        // we are returning number of subarrays with dis <= k
        unordered_map<int,int> mp; // to store freq
        int n = nums.size();
        int i = 0, j = 0;
        
        int ans = 0;
        
        while(j < n){
            mp[nums[j]]++;
            
            // we need to always have dis <= k
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            // means valid -- dis <= k
            // adding number of subarrays that end at index j
            ans += j - i + 1;
            j++;
        }
        
        // cout << ans << endl;
        return ans;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // <=3 - <=2 ----- === 3
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
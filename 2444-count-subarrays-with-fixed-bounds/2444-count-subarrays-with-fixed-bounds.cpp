class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mn, int ms) {
        int n = nums.size();
        int i = 0, mni = -1, msi = -1, id, clid = -1, t;
        long long ans = 0;
        
        /*
        in each iteration,
        + we update min idx, max idx --- we take min out of those and from that index, we can go left until we find the culprit idx
        + then we can add (id - clid) -- to give the number of subarrays for the ans     
        */
        
        for(int i = 0; i < n; i++){
            
            // updating msi, mni
            if(nums[i] == mn){
                mni = i;
            }
            if(nums[i] == ms){
                msi = i;
            }
            
            if(nums[i] < mn || nums[i] > ms){
                // culprit idx found
                clid = i;
            }
            
            // from that index, we go left until clid is found and can be added directly
            id = min(msi, mni);
            t = id - clid;
            ans += (t >= 0) ? t : 0;
        }
        
        
        return ans;
    }
};
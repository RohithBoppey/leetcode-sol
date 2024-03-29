class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        // first step is to find the max element
        // all positives
        int ms = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            ms = max(ms, nums[i]);
        }
        // cout << ms << endl;
        // now ms denotes the max element
        long long count = 0;
        int f = 0;
        int i = 0, j = 0;
        
        while(j < n){
            if(nums[j] == ms){
                f++;
            }
            // cout << f << endl;
            
            while(f >= k){
                // the current subarray configuration will be included in all the subarrays to the right
                count += n - j;
                
                // keep doing while removing i
                if(nums[i] == ms){
                    f--;
                }
                i++;
            }
                        
            j++;
        }
        
        return count;
    }
};
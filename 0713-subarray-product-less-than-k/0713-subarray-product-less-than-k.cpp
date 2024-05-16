class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // all are positives => contains no 0
        // so if k = 0 => then there will be no subarray that can give us a number less than zero
        if(k == 0 || k == 1){
            return 0;
        }
        
        long long int pr = 1;
        int ans = 0;
        
        int i = 0, j = 0, n = nums.size();
        
        while(j < n){
            
            // taking in j like in SLIDING WINDOW CONCEPT
            pr *= nums[j];
              
            // at the end of each iteration, we can check here
            // until it is greater we can keep pushing i
            while(pr >= k){
                pr = pr / nums[i]; 
                i++;
            }
            
            // once pushing i is done
            // we gotta add - ALL SUBARRAYS ENDING AT index - j
            ans += j - i + 1;
            
            // take the second number
            j++;
        }
        
        return ans;
    }
};
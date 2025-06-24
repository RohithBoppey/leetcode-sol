class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // using the sliding window approach 

        int n = nums.size();
        int ans = INT_MAX;

        int i = 0, j = 0, csum = 0;

        while(j < n){
            // add the jth element
            csum += nums[j];

            if(csum < target){
                // can increase the sliding window
            }else{
                // decrease until valid
                // csum >= target
                // cout << csum << endl;
                while(i <= j && csum >= target){
                    ans = min(ans, j - i + 1);
                    csum -= nums[i];
                    i++;
                }
            }
            
            j++;
        }

        return (ans == INT_MAX) ? 0 : ans; 
    }
};
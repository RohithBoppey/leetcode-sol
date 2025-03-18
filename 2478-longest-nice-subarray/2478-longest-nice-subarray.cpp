class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // using O(n²) solution

        int n = nums.size();
        int i = 0, j = 0;

        int running, ans = 0;

        // this for loop is to find the max length of the nice subarray starting from this position
        for(int i = 0; i < n; i++){
            // reset running for the next loop
            running = 0;
            for(int j = i; j < n; j++){
                if((running & nums[j]) != 0){
                    // i to j subarray is not nice
                    // no point in moving j
                    break;
                }

                // i to j subarray is nice
                // can proceed further
                running = (running | nums[j]);
                ans = max(ans, j - i + 1);

            }
        }  

        return ans; 
    }

};
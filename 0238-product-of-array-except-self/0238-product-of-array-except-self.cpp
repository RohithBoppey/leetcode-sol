class Solution {
public:
    int n;

    vector<int> productExceptSelf(vector<int>& nums) {
        // final optimized solution

        n = nums.size();

        //  calculate prefix and suffix on the go
        vector<int> ans(n, 1);

        int curr;
        // prefix
        curr = 1;
        // left sum
        for(int i = 0; i < n; i++){
            // update the current value with the prefix calculated so far
            ans[i] *= curr;
            // update current so it includes the current value --> need it for the next step
            curr *= nums[i];
        }

        // right sum
        curr = 1;
        for(int i = n - 1; i >= 0; i--){
            // take in the current value with suffix 
            ans[i] *= curr;
            curr *= nums[i];
        }

        return ans;

    }
};
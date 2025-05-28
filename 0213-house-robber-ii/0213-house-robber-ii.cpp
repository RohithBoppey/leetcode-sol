class Solution {
public:

    // returns the max amount he can rob, when start and end positions are given
    int solve(vector<int>& nums, int start, int end){
        int n = end - start + 1;
        if(n == 1){
            return nums[start];
        }

        // idea: to store max amount that can be robbed starting from the house i
        vector<int> r(n, 0);
        r[n - 1] = nums[end]; // can only rob this 1 store
        r[n - 2] = max(nums[end], nums[end - 1]);

        int c = r[n - 2]; // running pointer to store max

        if(n == 2){
            return c;
        }

        int rb, nrb;
        // start from 2 places behind
        for(int i = end - 2; i >= start; i--){
            // at any point, i can rob or not rob
            rb = nums[i] + r[i - start + 2];
            nrb = c;

            c = max(rb, nrb);

            r[i - start] = c;
        }

        return c;

    }

    int rob(vector<int>& nums) {
        int k = nums.size();
        if(k == 1) return nums[0];
        if(k == 2) return max(nums[0], nums[1]);

        int a = solve(nums, 0, k - 2);
        int b = solve(nums, 1, k - 1);
        return max(a, b);
    }
};
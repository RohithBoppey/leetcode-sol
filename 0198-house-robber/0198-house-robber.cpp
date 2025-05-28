class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        // idea: to store max amount that can be robbed starting from the house i
        vector<int> r(n, 0);
        r[n - 1] = nums[n - 1]; // can only rob this 1 store
        r[n - 2] = max(r[n - 1], nums[n - 2]);

        int c = r[n - 2]; // running pointer to store max

        if(n == 2){
            return c;
        }

        int rb, nrb;
        for(int i = n - 3; i >= 0; i--){
            // at any point, i can rob or not rob
            rb = nums[i] + r[i + 2];
            nrb = c;

            c = max(rb, nrb);

            r[i] = c;
        }

        return c;

    }
};
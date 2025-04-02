class Solution {
public:
    long long ans;
    int n;

    long long maximumTripletValue(vector<int>& nums) {
        ans = INT_MIN;
        n = nums.size(); 

        // find out the maxToRight Array
        vector<int> mx(n, -1);
        int last = nums[n - 1];
        mx[n - 1] = last;

        // now populate
        for(int i = n - 2; i >= 0; i--){
            mx[i] = last;
            last = max(last, nums[i]);
        }

        // now choose 2 and mul
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n - 1; j++){
                long long val = (long long)(nums[i] - nums[j]) * mx[j];
                cout << i << " " << j << " " << val << endl;
                if(val > ans){
                    ans = val;
                }
            }
        }

        return ans < 0 ? 0 : ans;

    }
};
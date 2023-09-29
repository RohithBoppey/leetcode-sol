class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            // either increasing or decreasing
            return true;
        }

        bool check, inc;
        // initial pattern

        int start = 0;
        while(start < n - 1){
            if(nums[start] == nums[start + 1]){
                start++;
            }else{
                break;
            }
        }

        if(start == n - 1){
            // reached the same
            // same number
            return true;
        }

        inc = (nums[start] < nums[start + 1]);
        for(int i = start + 1; i < n - 1; i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            check = (nums[i] < nums[i+1]);
            if(check != inc){
                return false;
            }
        }

        return true;
    }
};
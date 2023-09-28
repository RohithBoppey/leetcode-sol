class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums;
        }   
        
        int odd = n - 1;
        int even = 0;

        while(even <= odd){
            if(nums[even] % 2 == 0){
                // is even
                even++;
            }
            else if(nums[odd] % 2 == 1){
                odd--;
            }
            else {
                swap(nums[even], nums[odd]);
                even++;
                odd--;
            }
        }

        return nums;

    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int low = 0, high = n - 1, mid = 0;
        while(low < high){
            if(nums[low] < nums[high]){
                high--;
            }else{
                low++;
            }
        }
        
        return nums[low];
    }
};
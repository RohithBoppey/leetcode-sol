class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(target < nums[0] || target > nums[n-1]){
//             cannot be less than 0 or greater than max
//             hence return -1
            return -1;
        }
        
        
        int low = 0, high = n - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
//             we need to check for mid
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
//                 target is on left of mid
//                 hence we need to adjust the right end - high
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
//         if reached here, cannot return anything except -1
        return -1;
    }
};
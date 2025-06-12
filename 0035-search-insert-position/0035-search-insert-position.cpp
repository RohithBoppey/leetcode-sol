class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // handle the edge case seperately
        int n = nums.size(); 

        if(target < nums[0]){
            // at start
            return 0;
        } 
        if(target > nums[n - 1]){
            // at the end
            return n;
        }

        // binary search code
        int low = 0, high = n - 1, mid;

        while(low <= high){
            mid = low + (high - low) / 2;

            if(nums[mid] == target){
                return mid; // this is the index
            }
            else if(nums[mid] > target){
                // reduce the mid search space
                high = mid - 1;
            }else{
                // < target
                // should increase
                low = mid + 1;
            }
        }

        // if reached here, meaning low == high
        return low;
    }
};
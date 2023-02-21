class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        int low = 0, high = n - 1, mid = 0;
        while(low < high){
            mid = (low + high) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            if(mid % 2 == 0){
//                 even
                if(nums[mid] != nums[mid + 1]){
//                     on the right
                    high = mid;
                }else{
                    low = mid;  
                }
            }else{
//                 odd
                if(nums[mid] != nums[mid - 1]){
//                     on the left
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
        
        return nums[low];
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        
        if(n == 1){
            return;
        }
        
        // we are setting up low and high
//         while(nums[low] == 0){
//             low++;
//         }
        
//         while(nums[high] == 2){
//             high--;
//         }
        
//         mid = low;
//         while(nums[mid] == 1){
//             mid++;
//         }
        
        // now we have the boundaries
        // we need to solve
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                // 2
                swap(nums[high], nums[mid]);
                high--;
            }
        }
        
    }
};
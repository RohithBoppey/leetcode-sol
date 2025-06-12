Classic standard problem,, easy to solve. 
Handle just the equal to condition and when low and high are equal -> loop gets exited, but you should return the index

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // using binary search
        int n = nums.size(); 

        int low = 0, high = n - 1, mid;

        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                // should increase
                low = mid + 1;
            }else{
                // > target
                high = mid - 1;
            }
        }

        // if both coincide, meaning exist
        return (nums[low] == target) ? low : -1;
    }
};
```

Very similar to Binary search problem. 

But some changes: 
- low <= high should be there, coz the element can be present at the low == high element as well
- when low <= high, assuming the loop broke, the boundary conditions adjust automatically.

```c++
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
```

Without low <= high code, some more boundary conditions: 
```c++
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

        // low == high
        if(nums[low] == target){
            return low;
        }

        return (nums[low] > target) ? low : low + 1;
    }

    int searchInsert(vector<int>& nums, int target) {
        if(target <= nums[0]){
            // should insert at the begining
            return 0;
        }

        return search(nums, target);
    }
};
```​




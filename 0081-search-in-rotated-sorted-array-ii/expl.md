- The underlying idea is the same, but
- The hard part is to identify whether the mid is belonging to left sorted or right sorted. Ex: `[1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1`
- Like how do you identify if you are in left or right sorted?
- How were we identifying previously? It is via: nums[left] >= nums[mid], but here if nums[left] == nums[mid], we are unable to identify
- Hence, we can do `if nums[mid] == nums[left], move left: left++`
- So the left keeps moving until binary search is possible, and when possible, binary search happens. 

```c++
class Solution {
public:
    int n;

    int search2(vector<int>& nums, int target) {
        n = nums.size(); 
        // using binary search directly in a different way

        // at any point, the mid can be either in left sorted array or right sorted array
        int low = 0, high = n - 1, mid;

        while(low <= high){
            mid = low + (high - low) / 2;
            // cout << mid << endl;
            if(nums[mid] == target){
                return mid;
            }

            // now checking if it is in left sorted or right sorted
            if (nums[mid] > nums[low]){
                // left sorted
                if(nums[mid] < target){
                    // MUST go right
                    low = mid + 1;
                }else{
                    // compare with left min
                    if(target < nums[low]){
                        // not present in left, move to right
                        low = mid + 1;
                    }else{
                        // it is present in left, and less than mid
                        high = mid - 1;
                    }
                }
            }else if (nums[mid] < nums[low]){
                // right sorted
                if(nums[mid] > target){
                    // MUST move left
                    high = mid - 1;
                }
                else{
                    // can move left or right - decide on nums[right] value
                    if(target > nums[high]){
                        // not present in right sorted - move left
                        high = mid - 1;
                    }else{
                        // present within right sorted, but greater than min
                        low = mid + 1;
                    }
                }
            }else{
                // mid and left are equal, we cannot identify if it is right sorted or left sorted, so
                low++;
            }

        }

        return -1;

    }

    bool search(vector<int>& nums, int target) {
        return (search2(nums, target) == -1) ? false : true;
    }
};
```

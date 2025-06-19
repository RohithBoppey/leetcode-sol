- using 2 pointers to solve the problem
- point to high and low for start and end
- based on the sum value reduce the search space

```c++
class Solution {
public:
    vector<int> res;

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int sum;

        while(low < high){
            sum = nums[low] + nums[high];
            if(sum == target){
                return {low + 1, high + 1};
            }
            if(sum > target){
                high--;
            }else{
                low++;
            }
        }

        return {-1, -1};
    }
};
```

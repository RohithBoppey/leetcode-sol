- one is always the lag pointer, and one will always move forward to show the non k value
- the i pointer will always point to where the next non k value is inserted
- and j pointer moves from 0 to n and if nums[j] != given k, that means, insert at the ith position
- so finally when you're at i, that means all the left values of i are filled with non-k values from the right, that can be returned

```c++
class Solution {
public:
    int n;
    int removeElement(vector<int>& nums, int val) {
        n = nums.size();
        int i = 0, j = 0; 
        while(j < n){
            if(nums[j] != val){
                // replace it with the current i
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
```

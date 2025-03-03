Using 3 arrays, brute force solution: 
  
```c++
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before, after;
        int i = 0, n = nums.size(), pcount = 0;

        while(i < n){
            if(nums[i] < pivot){
                before.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                after.push_back(nums[i]);
            }
            else{
                // equal
                pcount++;
            }
            i++;
        }

        // first before, then pcount, then after
        vector<int> res;
        i = 0, n = before.size();
        while(i < n){
            res.push_back(before[i]);
            i++;
        }

        while(pcount--){
            res.push_back(pivot);
        }

        i = 0, n = after.size();
        while(i < n){
            res.push_back(after[i]);
            i++;
        }

        return res;
    }
};
```

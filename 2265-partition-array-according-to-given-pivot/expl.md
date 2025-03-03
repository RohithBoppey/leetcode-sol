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

Slightly optmimised solution (playing with count of low, equal numbers and indices from where the array would start) - 
![WhatsApp Image 2025-03-03 at 23 05 39_16d9eb1a](https://github.com/user-attachments/assets/d9630063-2ace-4d91-a9e9-1423060d40f6)

```c++
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // using the starting positions to fill in the new array
        int n = nums.size();

        vector<int> res(n, 0);
        int lown = 0, equaln = 0;
        for(auto x: nums){
            if(x < pivot){
                lown++;
            }
            else if(x == pivot){
                equaln++;
            }
        }

        // start filling from the starting pos
        int low = 0, equal = lown, high = lown + equaln;
        int i = 0;
        while(i < n){
            if(nums[i] < pivot){
                res[low] = nums[i];
                low++;
            }
            else if(nums[i] > pivot){
                res[high] = nums[i];
                high++;
            }
            else{
                // equal
                res[equal] = nums[i];
                equal++;
            }
            i++;
        }

        return res;
    
    }
};
```

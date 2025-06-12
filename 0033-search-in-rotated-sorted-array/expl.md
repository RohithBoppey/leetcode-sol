Optimized solution: 
- The idea is to consider there are 2 different sorted arrays put side by side
- at any point, the mid can be present in left sorted or right sorted
- write the cases for: if mid in left sorted and > target, < target and same for right sorted
- write on paper while solving it

```c++
class Solution {
public:
    int n;

    int search(vector<int>& nums, int target) {
        n = nums.size(); 
        // using binary search directly in a different way

        // at any point, the mid can be either in left sorted array or right sorted array
        int low = 0, high = n - 1, mid;

        while(low <= high){
            mid = low + (high - low) / 2;
            cout << mid << endl;
            if(nums[mid] == target){
                return mid;
            }

            // now checking if it is in left sorted or right sorted
            if (nums[mid] >= nums[low]){
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
            }else{
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
            }

        }

        return -1;

    }
};
```



My idea: 
The whole idea is make to the mapping from newIndex to the oldIndex (actual array given) and perform normal binary search on the newIndex

```c++
class Solution {
public:
    
    int n;
    int findPivot(vector<int>& nums){
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                return i + 1;
            }
        }
        return 0;
    }
    
    int oldInd(int &newInd, int &piv){
        return (newInd + piv) % n;
    }

    void printAllPivots(vector<int>& nums, int piv){
        for(int i = 0; i < n; i++){
            cout << i << "->" << oldInd(i, piv) << endl;
        }
    }

    int search(vector<int>& nums, int target) {
        // using old index. new index concept

        n = nums.size(); 

        int low = 0, high = n - 1, mid;
        int oind, oval;

        // find the pivot element
        int piv = findPivot(nums);
        // printAllPivots(nums, piv);
        
        while(low <= high){
            mid = low + (high - low) / 2;

            oind = oldInd(mid, piv);

            if(nums[oind] == target){
                // found
                return oind;
            }else if(nums[oind] > target){
                // reduce search space
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return -1;

    }
};
```

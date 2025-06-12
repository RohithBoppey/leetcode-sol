
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

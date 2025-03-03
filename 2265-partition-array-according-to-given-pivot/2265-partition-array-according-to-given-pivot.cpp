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
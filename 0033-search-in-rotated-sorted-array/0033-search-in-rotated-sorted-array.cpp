class Solution {
public:
    int n; 
    int pivot; 

    void findPivot(vector<int>& nums){
        int i = 0;
        for(i = 0; i < n - 1; i++){
            // if it drops, then the next index where it drops is the pivot
            if(nums[i] > nums[i + 1]){
                break;
            }
        }

        // it reached n
        pivot = (i + 1) % n;
        return; 
    }

    // find old to new index
    int oldInd(int newInd){
        return (newInd + pivot) % n;
    }

    void printPivot(vector<int>& nums){
        for(int i = 0; i < n; i++){
            cout << oldInd(i) << " "; 
        }
        cout << endl; 
    }

    int search(vector<int>& nums, int target) {
        n = nums.size();

        findPivot(nums); 
        // cout << pivot << endl;

        int low = 0, high = n - 1, mid; 

        // printPivot(nums);

        while(low <= high){
            mid = low + (high - low) / 2; 
            int md = oldInd(mid);

            if(nums[md] == target){
                return md; 
            }else if(nums[md] > target){
                // should reduce
                high = mid - 1;
            }else{
                // move right - increase
                low = mid + 1;
            }
        }

        return -1; 
    }
};
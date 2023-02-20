class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        if(target <= v[0]){
            return 0;
        }
        int n = v.size();
        if(target > v[n-1]){
            return n;
        }
        int low = 0, high = n - 1, mid = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(v[mid] == target){
                return mid;
            }else if(v[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return low;
    }
};
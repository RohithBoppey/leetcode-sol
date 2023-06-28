class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find rows and cols
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // since they are in order, we can use binary search
        
        // number of indices - [0, (rows*cols) - 1]
        
        int low = 0, high = (rows*cols) - 1;
        int mid;
        
        int ri, ci;
        
        // new 1
        while(low <= high){
            mid = low + (high - low) / 2;
            ri = mid / cols, ci = mid % cols;
            if(matrix[ri][ci] == target){
                // we found the element
                cout << "found at row: " << ri << " col: " << ci << endl;
                return true;
            }else if(matrix[ri][ci] > target){
                // reduce the high
                high = mid - 1;
            }else{
                // matrix[ri][ci] < target
                low = mid + 1;
            }
        }
        
        return false;
    }
};
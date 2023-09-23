class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // we have indexes from [0, n - 1]
        int left = 0, right = (rows*cols) - 1, mid;
        int row, col;
        
        while(left <= right){
            mid = left + (right - left) / 2;
            row = mid / cols;
            col = mid % cols;
            
            if(matrix[row][col] == target){
                // found
                return true;
            }
            
            else if(matrix[row][col] < target){
                // modify left
                left = mid + 1;
            }
            
            else{
                right = mid - 1;
            }
            
        }
        
        return false;
        
    }
};
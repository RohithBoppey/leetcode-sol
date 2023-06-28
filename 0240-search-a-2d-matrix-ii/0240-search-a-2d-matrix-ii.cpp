class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // finding the rows and cols
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // low and high
        
        int low = 0, high = cols - 1;
        
        // neither of them can go below 0
        while(low < rows && high >= 0){
            if(matrix[low][high] == target){
                // found
                return true;
            }else if(matrix[low][high] > target){
                high--;
            }else{
                // matrix[low][high] < target
                // should go down
                low++;
            }
        }
        
        return false;
    }
};
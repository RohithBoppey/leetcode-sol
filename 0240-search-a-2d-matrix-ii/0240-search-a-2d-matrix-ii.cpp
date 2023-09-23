class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int low = 0, high = cols - 1;
        
        while(low < rows && high >= 0){
            if(matrix[low][high] == target){
                return true;
            }
            else if(matrix[low][high] > target){
                // move left
                high--;
            }
            else{
                low++;
            }
        }
        
        return false;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> rowm(rows, 0);
        vector<int> colm(cols, 0);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    // found a 0
                    rowm[i] = 1;
                    colm[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rowm[i] == 1 || colm[j] == 1){
                    // found a 0
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};
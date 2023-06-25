class Solution {
public:
    
    void transpose(vector<vector<int>>& matrix){
        int rows = matrix.size();
        int cols = rows;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
    
    void rotate(vector<vector<int>>& matrix) {
        // LOGIC - transpose and reverse each row
        int rows = matrix.size();
        int cols = rows;
        
        // given n * n 
        transpose(matrix);
        for(int i = 0; i < rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
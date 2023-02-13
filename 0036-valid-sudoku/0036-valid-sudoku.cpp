class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board){
//         check row, check col and check submatrix
//         check row
        char val = board[row][col];
        for(int i = col + 1; i < 9; i++){
            if(val == board[row][i]){
//                 found the same
                return false;
            }
        }
        
//         check col
        for(int i = row + 1; i < 9; i++){
            if(val == board[i][col]){
//                 found the same
                return false;
            }
        }
        
//         check submatrix
        
//         finding rowStart and colStart
        int rowS = 0, colS = 0;
        for(int i = 0; i < 9; i = i + 3){
            if(row >= i && row < i + 3){
                rowS = i;
            }
            if(col >= i && col < i + 3){
                colS = i;
            }
        }
        
        // cout << rowS << colS << endl;
        
//         submatrix check
        for(int i = rowS; i <= rowS + 2; i++){
            for(int j = colS; j <= colS + 2; j++){
                if(board[i][j] == val && (i != row && j != col)){
                    // cout << "found" << endl;
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] != '.'){
//                     some value present
                    if(solve(i, j, board) == false){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
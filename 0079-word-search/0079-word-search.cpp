class Solution {
public:
    int rows, cols, n;

    bool solve(vector<vector<char>>& board, string& word, int r, int c, int start){
        if(start == n){
            // word limit reached
            return true; 
        }
        
        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[start]){
            // boundary reached or word not matched
            return false; 
        }


        // traverse each direction
        // and if the word exists in any direction, return true
        char ch = board[r][c];
        board[r][c] = '0';

        if(
            solve(board, word, r - 1, c, start + 1) || 
            solve(board, word, r + 1, c, start + 1) || 
            solve(board, word, r, c + 1, start + 1) || 
            solve(board, word, r, c - 1, start + 1)
            ){
                return true; 
            }

        board[r][c] = ch;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size(); 
        cols = board[0].size();

        n = word.size(); 

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == word[0]){
                    // found the starting position
                    if(solve(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }

        return false;

    }
};
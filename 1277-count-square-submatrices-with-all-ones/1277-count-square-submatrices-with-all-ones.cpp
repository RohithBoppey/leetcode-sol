class Solution {
public:
    
    int minOfThree(int &a, int &b, int &c){
        return min(min(a, b), c);
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        int res = 0;
//         initialsisation
        for(int i = 0; i < rows; i++){
            dp[i][0] = matrix[i][0];
        }
        for(int i = 0; i < cols; i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + minOfThree(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
                }
            }
        }
        
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                res += dp[i][j];
            }
        }
        
        return res;
    }
};
class Solution {
public:
    int min1(int a, int b, int c){
        return min(a, min(b, c));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        // initialsing
        int mx = 0;
        for(int i = 0; i < rows; i++){
            // col has to be 0
            dp[i][0] = matrix[i][0] - '0';
            mx = max(mx, dp[i][0]);
        }

        for(int j = 0; j < cols; j++){
            // row 0
            dp[0][j] = matrix[0][j] - '0';
            mx = max(mx, dp[0][j]);
        }

        int left, up, diag;
        
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        // processing
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == '0'){
                    // checking
                    dp[i][j] = 0;
                }else{
                    // should check in 3 directions 
                    left = dp[i][j - 1];
                    up = dp[i - 1][j];
                    diag = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min1(left, up, diag);
                }

                mx = max(mx, dp[i][j]);
            }
        }

        
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return mx * mx;

    }
};
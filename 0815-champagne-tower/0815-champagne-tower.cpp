class Solution {
public:
    double champagneTower(int poured, int r, int c) {
        double p = (double) poured;
        double dp[105][105] = {0.0};

        dp[0][0] = p;
        double rem = 0;

        for(int i = 0; i < 101; i++){
            bool flag = false;
            for(int j = 0; j <= i; j++){
                if(dp[i][j] > 1){
                    // must divide and add to next rows
                    flag = true;
                    rem = dp[i][j] - 1;
                    dp[i][j] = 1;
                    dp[i + 1][j] += (rem / 2.0);
                    dp[i + 1][j + 1] += (rem / 2.0);
                }
            }
            if(flag == false){
                break;
            }
        }

        // need not calc
        // return min(1.00, dp[r][c]);
        return dp[r][c];
    }
};
![image](https://user-images.githubusercontent.com/73538974/270189352-859dccc1-df5a-4011-b077-72ef81c837d3.png)
![image](https://user-images.githubusercontent.com/73538974/270189363-b9da2a20-7050-42eb-a9e4-2c7556fd3e8b.png)
![image](https://user-images.githubusercontent.com/73538974/270189373-6b4c2ba7-e5a5-4a7e-9a9c-abae89ab5222.png)
![image](https://user-images.githubusercontent.com/73538974/270189382-2eb58ce1-988d-4838-b9c9-0bde111efebe.png)
      
```
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
```

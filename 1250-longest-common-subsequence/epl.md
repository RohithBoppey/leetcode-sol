Can include printing logic as well in the same question just while taking it.
  
Follows the idea of knapsack kind of problem:   
![WhatsApp Image 2025-02-28 at 10 04 45_1b50b8f1](https://github.com/user-attachments/assets/51e24670-705b-43c6-809e-d7c1489df06c)

  
```c++
class Solution {
public:
    void print2D(vector<vector<int>>& dp){
        for(auto &x : dp){
            for(auto &y: x){
                cout <<  y<< " ";
            }
            cout << endl;
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        // take the len * len array
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        string s = "";

        // processing
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(text1[i - 1] == text2[j - 1]){
                    // must take in the subsequence
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    s += text1[i - 1];
                }else{
                    // go in the direction of max
                    int first, second;
                    first = dp[i - 1][j];
                    second = dp[i][j - 1];

                    dp[i][j] = max(first, second);
                }
            }
        }

        return dp[n1][n2];
    }
};
```

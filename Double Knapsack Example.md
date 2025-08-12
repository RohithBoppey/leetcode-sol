```c++
int maxWeight(vector<int> &arr, int capacity1, int capacity2) {
    int n = arr.size();

    // Initialize a 3D DP array with dimensions (n+1) x (w1+1) x (w2+1)
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>
                                   (capacity1 + 1, vector<int>(capacity2 + 1, 0)));

    // Fill the DP array iteratively
    for (int i = 1; i <= n; ++i) {
        int weight = arr[i - 1];
        for (int j = 0; j <= capacity1; ++j) {
            for (int k = 0; k <= capacity2; ++k) {

                // Option 1: Don't take the current item
                dp[i][j][k] = dp[i - 1][j][k];

                // Option 2: Take the current item in the
              	// first knapsack, if possible
                if (j >= weight) {
                    dp[i][j][k] = max(dp[i][j][k], weight + dp[i - 1][j - weight][k]);
                }

                // Option 3: Take the current item in the
              	// second knapsack, if possible
                if (k >= weight) {
                    dp[i][j][k] = max(dp[i][j][k], weight + dp[i - 1][j][k - weight]);
                }
            }
        }
    }

    
    return dp[n][capacity1][capacity2];
}

int main() {
    vector<int> arr = {8, 2, 3};
    int capacity1 = 10, capacity2 = 3;
    int res = maxWeight(arr, capacity1, capacity2);
    cout <<  res;
    return 0;
}
```

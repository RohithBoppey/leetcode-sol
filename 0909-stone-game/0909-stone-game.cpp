class Solution {
public:
    vector<vector<int>> dp;
    int n;

    void print2d(vector<vector<int>>& dp){
        for(auto &x: dp){
            for(auto &y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }

    int maxAliceStones(vector<int>& p, int l, int r){
        if (l > r){
            // alice gets no stones
            return 0;
        }

        if (dp[l][r] != -1){
            return dp[l][r];
        }

        // processing
        // at any point, can take from start or end
        int sz = r - l + 1;

        // alice can only pick if there is even number of elements in the subarray
        int left, right, isEven;
        isEven = !(sz % 2);

        left = isEven ? p[l] : 0;
        right = isEven ? p[r] : 0;

        return dp[l][r] = max(left + maxAliceStones(p, l + 1, r), right + maxAliceStones(p, l, r - 1));
    }

    bool stoneGame(vector<int>& piles) {
        // in this approach, only consider the alice counts
        n = piles.size(); 
        dp.resize(n, vector<int>(n, -1));

        // the max number of tokens that Alice can pick, and it should be majority
        int sum = 0;
        for(auto &x: piles){
            sum += x;
        }

        // if alice has majority stones that means she passed
        maxAliceStones(piles, 0, n - 1);
        return dp[0][n - 1] > sum / 2;
    }
};
**O(1) solution**
- Alice will win no matter what
- The reason is that if alice wants, she can choose the entire even element subset => {0,2,4,...} or the odd element subset => {1,3,5,...}
- and in the question given that one part of the array is greater than another
- hence Alice's win is guaranteed
- so doing `return True` will also work

**Ideal solution**
- instead of maintaining track of both alice and bob counts
- only focus on the max difference that can be achieved between Alice - Bob
- this can be done by: at any left, right: the net gain would be (selecting + proceeding)

```c++
class Solution {
public:
    vector<vector<int>> dp;

    void print2d(vector<vector<int>>& dp){
        for(auto &x: dp){
            for(auto &y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }

    int solve(vector<int>& p, int left, int right){
        if(left > right){
            // nothing
            return 0;
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        // at any point, can pick from left or right
        int l = p[left] - solve(p, left + 1, right);
        int r = p[right] - solve(p, left, right - 1);

        return dp[left][right] = max(l, r);
    }

    bool stoneGame(vector<int>& piles) {
        // the idea is to use a function which can determine how much more tokens can Alice have at the end
        int n = piles.size(); 
        dp.resize(n, vector<int>(n, -1));
        solve(piles, 0, n - 1) > 0;
        // print2d(dp);
        return dp[0][n - 1];
    }
};
```


**Complete intuition (MY APPROACH)**: 
- at any point, I am checking whether Alice can win or not
- for that, I am storing alice count, bob count, turn, left pointer and right pointer
- at any point, the person can take the array from the left or the right
- hence, we get 4 conditions: alice: left, right or bob: left, right based on the turn parameter
- since there could be repeating subproblems, memoized using map & string

```c++
class Solution {
public:

    unordered_map<string, bool> memo;

    bool solve(vector<int>& p, int f, int l, int turn, int ac, int bc){
        if(f > l){
            // reached the end
            return (ac > bc) ? true : false; 
        }

        // check from the tree
        string key = to_string(f) + "-" + to_string(l) + "-" + to_string(turn);
        if(memo.find(key) != memo.end()){
            return memo[key];
        }

        // did not reach the end
        // at any point, we can take the pile from first or last
        bool left = false, right = false;
        if(turn == 0){
            // alice turn
            left = solve(p, f + 1, l, !turn, ac + p[f], bc);
            right = solve(p, f, l - 1, !turn, ac + p[l], bc);
        }else{
            // bob turn
            left = solve(p, f + 1, l, !turn, ac, bc + p[f]);
            right = solve(p, f, l - 1, !turn, ac, bc + p[l]);
        }

        // either from left or right, is Alice able to win?
        return memo[key] = left || right; 
    }

    bool stoneGame(vector<int>& p) {
        int n = p.size(); 
        return solve(p, 0, n - 1, 0, 0, 0);   
    }
};
```

**Focusing only on Alice Contribution**
```c++
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
```




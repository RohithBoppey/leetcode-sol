**O(1) solution**
- Alice will win no matter what
- The reason is that if alice wants, she can choose the entire even element subset => {0,2,4,...} or the odd element subset => {1,3,5,...}
- and in the question given that one part of the array is greater than another
- hence Alice's win is guaranteed
- so doing `return True` will also work

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

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
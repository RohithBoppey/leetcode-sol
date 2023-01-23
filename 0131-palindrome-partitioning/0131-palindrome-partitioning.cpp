
#define pb push_back
class Solution {
public:

    bool isPart(string& s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void solve(int start, string &s, vector<string>& curr, vector<vector<string>>& res, int& n){
        if(start == n){
            res.pb(curr);
            return;
        }

        // find all possible permutations
        for(int i = start; i < n; i++){
            // check the left from i is a partition or not
            if(isPart(s, start, i)){
                curr.pb(s.substr(start, i - start + 1));
                solve(i + 1, s, curr, res, n);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        if(n == 1){
            res.pb({s});
            return res;
        }
        int start = 0;
        vector<string> curr;
        solve(start, s, curr, res, n);
        return res;
    }
};
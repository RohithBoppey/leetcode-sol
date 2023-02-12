class Solution {
public:
    vector<vector<char>> ch = 
        {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };

    void solve(string& digits, int i, string& curr, int &n, vector<string>& res){
        if(i == n){ 
            res.push_back(curr);
            return;
        }
        int k = digits[i] - '0'; 
        for(auto x: ch[k - 2]){
            curr += x;
            solve(digits, i + 1, curr, n, res);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        if(n == 0){
            return {};
        }
        string curr = "";
        solve(digits, 0, curr, n, res);
        return res;
    }
};
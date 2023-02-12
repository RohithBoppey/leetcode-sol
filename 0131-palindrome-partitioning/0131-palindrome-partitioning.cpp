class Solution {
public:
    bool isPartition(int start, int end, string& s){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }   
            start++;
            end--;
        }
        return true;
    }
    
    
    void solve(int start, vector<string>& curr, vector<vector<string>>& res, int& n, string &s){
        if(start == n){
//             end of the string
            res.push_back(curr);
            return;
        }
        
        for(int i = start; i < n; i++){
            if(isPartition(start, i, s) == true){
//                 that part is partition, we can break into multiple pieces
                curr.push_back(s.substr(start, i - start + 1));
                solve(i + 1, curr, res, n, s);
                curr.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        if(n == 0){
            return {{s}};
        }
        
        vector<string> curr;
        vector<vector<string>> res;
        int start = 0;
        solve(start, curr, res, n, s);
        return res;
    }
};
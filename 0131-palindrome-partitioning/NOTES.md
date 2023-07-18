```
class Solution {
public:
    
    bool isPalindrome(string& s, int start, int end){
        
        while(start <= end){
            if(s[start] != s[end]){
                return false;   
            }
            start++;
            end--;
        }
        
        return true;
    }
    
    void solve(string& s, int start, vector<string>& curr, int& n, vector<vector<string>>& result){
        
        if(start >= n){
            // reached the end so nothing can be done
            result.push_back(curr);
            return;
        }
        
        // from the start position, check for the palindrome
        for(int i = start; i < n; i++){
            
            if(isPalindrome(s, start, i) == true){
                
                // the current window is a palindrome, so we are adding it into the current strings
                
                // adding it into the current
                curr.push_back(s.substr(start, i - start + 1));
                solve(s, i + 1, curr, n, result);
                curr.pop_back();
                
            }
            
        }
        
        
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        int start = 0;        
        vector<string> curr;
        vector<vector<string>> result;
        solve(s, start, curr, n, result);
        return result;
    }
};
```​

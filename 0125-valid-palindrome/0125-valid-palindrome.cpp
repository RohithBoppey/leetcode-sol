class Solution {
public:
    bool solve(string& s){
        int n = s.size();
        for(int i = 0; i < n / 2; i++){
            if(s[i] != s[n - i - 1]){
                return false;
            }
        }
        return true; 
    }

    char toLowercase(char& ch){
        return (char)((ch - 'A') + 'a');
    }

    bool isNumeric(char& ch){
        return (ch - '0') <= 9 && (ch - '0') >= 0;
    }

    bool isPalindrome(string s) {
        string cleaned = "";
        for(auto &ch: s){
            if(ch >= 'a' && ch <= 'z'){
                // lowercase, can add directly
                cleaned += ch;
            }else if(ch >= 'A' && ch <= 'Z'){
                // make it lowercase, and then return
                cleaned += toLowercase(ch);
            }else if(isNumeric(ch)){
                cleaned += ch;
            }
            else{
                continue;
            }
        }

        return solve(cleaned);

    }
};
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // since constructing string might give us memory limit exceeded
        int n = s.size();
        long long int len = 0, ind;
        char ch;

        string result = "";

        for(int i = 0; i < n; i++){
            ch = s[i];
            if(ch >= 'a' && ch <= 'z'){
                // is a char
                len++;
            }else{
                // is a number
                ind = ch - '0';
                len *= ind;
            }
        }

        // now start from behind and find until k == 0
        for(int i = n - 1; i >= 0; i--){
            ch = s[i];
            k = k % len;
            if(k == 0 && isalpha(ch)){
                result +=  ch;
                return result;
            }
            if(ch >= 'a' && ch <= 'z'){
                len--;

            }else{
                ind = ch - '0';
                len /= ind;
            }
        }

        return "";
    }
};
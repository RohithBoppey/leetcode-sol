class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        string res = "";
        
        int l, r, n = s.size(), sz;
        
        // checking for odd and even palindromes
        
        for(int i = 0; i < n; i++){
            // we need to check for each index
            
            // odd palindrome
            l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                // in bound and is a palindrome so far
                sz = r - l + 1;
                if(sz > len){
                    // found a bigger window
                    res = s.substr(l, sz);
                    len = sz;
                }
                l--;
                r++;
            }
            
            // even palindrome
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                // in bound and is a palindrome so far
                sz = r - l + 1;
                if(sz > len){
                    // found a bigger window
                    res = s.substr(l, sz);
                    len = sz;
                }
                l--;
                r++;
            }
        }
        
        return res;
    }
};
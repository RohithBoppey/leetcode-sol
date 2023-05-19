class Solution {
public:
    int countSubstrings(string s) {
        // using the same logic as longest palindrome substring
        int n = s.size();
        int l, r;
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            // odd palindromes
            l = i, r = i;
            while(l > -1 && r < n && s[l] == s[r]){
                // is a palindrome and valid
                count++;
                l--;
                r++;
            }
            
            // even palindormes
            // odd palindromes
            l = i, r = i + 1;
            while(l > -1 && r < n && s[l] == s[r]){
                // is a palindrome and valid
                count++;
                l--;
                r++;
            }
        }
        
        return count;
    }
};
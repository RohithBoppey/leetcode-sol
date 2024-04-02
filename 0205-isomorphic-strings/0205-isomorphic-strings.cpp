class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // to compare freq
        unordered_map<char, char> m1, m2;
        int n = s.size();
        for(int i = 0; i < n; i++){
             if( 
                (m1.find(s[i]) != m1.end() && m1[s[i]] != t[i]) ||
                (m2.find(t[i]) != m2.end() && m2[t[i]] != s[i])
               ){
                 return false;
             }
            
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        
        // all letters freq same, so they can be replaced
        return true;
    }
};
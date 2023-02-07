class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        int m = s.size(), n = t.size();
        if(m != n){
            return false;
        }
        for(int i = 0; i < m; i++){
            v1[s[i] - 'a']++;
            v2[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        
        return true;
    }
};
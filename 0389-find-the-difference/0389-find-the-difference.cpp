class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v1(26, 0), v2(26, 0);
        int n1 = s.size();
        int n2 = t.size();
        for(int i = 0; i < n1; i++){
            v1[s[i] - 'a']++;
        }
        for(int i = 0; i < n2; i++){
            v2[t[i] - 'a']++;
        }
        // compare and return the extra one
        for(int i = 0; i < 26; i++){
            if(v1[i] != v2[i]){
                // one is extra in v2
                return (char)('a' + i);
            }
        }
        return 'z';
    }
};
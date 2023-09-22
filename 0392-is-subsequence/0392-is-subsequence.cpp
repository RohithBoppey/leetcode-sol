class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        
        int p1 = 0, p2 = 0;
        
        while(p1 < n1){
            while(p2 < n2 && s[p1] != t[p2]){
                p2++;
            }
            if(p2 == n2){
                // reached the end
                return false;
            }else{
                p2++;
            }
            p1++;
        }
        
        return true;
        
    }
};
class Solution {
public:
    // maintaining 2 freq
    vector<int> f1;
    vector<int> f2;

    bool checkIfSame(){
        for(int i = 0; i < 26; i++){
            if(f1[i] != f2[i]){
                return false;
            }
        }
        return true; 
    }

    bool checkInclusion(string s1, string s2) {
        f1.resize(26, 0);
        f2.resize(26, 0);

        // populate
        for(auto &ch: s1){
            f1[ch - 'a']++;
        }

        // using sliding window
        int i = 0, j = 0;
        
        /*
        since s1 and s2 min condition is given: ------------------------
        string mn = (s1.size() <= s2.size()) ? s1 : s2; 
        string mx = (mn == s1) ? s2 : s1;

        // cout << mn << " " << mx << endl;

        // always use min string length to compare
        int mns = mn.size(); 
        int n = mx.size(); 
        
        */

        int n = s2.size();

        while(j < n){
            // expand until mns reached
            f2[s2[j] - 'a']++;

            if(j - i + 1 < s1.size()){
                // should expand
            }else{ 
                // size met
                // hence always move right maintaining this
                if(checkIfSame()){
                    return true;
                }
                // not same, move right, so move i
                f2[s2[i] - 'a']--;
                i++;
            }
            j++;
        }
        
        return false;


    }
};
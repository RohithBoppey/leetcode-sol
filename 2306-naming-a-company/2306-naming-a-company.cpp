class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        vector<unordered_set<string>> mp(26);
        for(auto &s: ideas){
            mp[s[0] - 'a'].insert(s.substr(1));
        }
        
        int u1 = 0, u2 = 0;
        for(int i = 0; i < 25; i++){
            for(int j = i + 1; j < 26; j++){
//                 compare every i and j
                u1 = 0; u2 = 0;
                for(auto &s: mp[i]){
//                     check if exsists in j
                    if(mp[j].find(s) == mp[j].end()){
//                         not found
                        u1++;
                    }
                }
                for(auto &s: mp[j]){
//                     check if exsists in j
                    if(mp[i].find(s) == mp[i].end()){
//                         not found
                        u2++;
                    }
                }
                
                // cout << u1 << " " << u2 << endl;
                res += u1 * u2;
//                 u1 * u2 perms can be possible
            }
        }
        return (2 * res);
    }
};
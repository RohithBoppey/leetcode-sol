class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for(auto x: s1){
            mp[x]++;
        }
        
//         using the concept of sliding window
//         window size = s1.size();
        int k = s1.size(), i = 0, j = 0;
        int n = s2.size();
        int count = mp.size();
        while(j < n){
            if(mp.find(s2[j]) != mp.end()){
//                 means that is found
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){
                    count--;
                }
            }
            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
//                 window size matched
//                 should remove from the back
//                 remove from i
                if(count == 0){
                    return true;
                }
                if(mp.find(s2[i]) != mp.end()){
//                     found, add back the frequency
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        
        return false;
    }
};
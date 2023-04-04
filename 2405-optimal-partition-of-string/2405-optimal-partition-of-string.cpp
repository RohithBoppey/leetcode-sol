class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        unordered_map<char,int> mp;
        for(auto ch: s){
            if(mp[ch] >= 1){
                mp.clear();
                count++;
            }
            mp[ch]++;
        }
        return count;
    }
};
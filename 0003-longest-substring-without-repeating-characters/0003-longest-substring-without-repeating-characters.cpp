class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }

        int i = 0, j = 0;
        int res = 0;
        unordered_map<char, int> mp;
        while(j < n){
            // right limit reaches the end
            mp[s[j]]++;
            // check window size
            if(j - i + 1 == mp.size()){
                // all are unique
                res = max(res, j - i + 1);
                j++;
            }else{
                // mostly due to what case? 
                // window size > mp.size();
                while(j - i + 1 > mp.size()){
                    // until there are duplicate elements in the system
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }   
        }

        return res;
    }
};
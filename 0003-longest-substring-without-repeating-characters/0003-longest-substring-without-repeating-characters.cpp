class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();

        unordered_map<char, int> mp;
        int mx = 0;
        int ws = 0;

        int start = 0, end = 0;
        while(end < n){
            // insert the position in the end 
            mp[s[end]]++;

            // check if the window size is equal to the unique count (keys) in the mp
            ws = end - start + 1;
            if(ws == mp.size()){
                // all the letters in the window are unique, and in the map as well, no duplicates are found
                mx = max(mx, ws);
            }

            else{
                // one thing which is clear is that always ws >= mp.size()
                while(mp.size() != ws){
                    mp[s[start]]--;
                    if(mp[s[start]] == 0){
                        mp.erase(s[start]);
                    }
                    start++;
                    ws = end - start + 1;
                }
            }

            end++;
        }

        return mx;
    }
};
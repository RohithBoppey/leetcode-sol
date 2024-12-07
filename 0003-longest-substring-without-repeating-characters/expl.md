​By using the map and a basic sliding window problem, we can solve this: 

Imagine we are putting all the letters from left to right one by one in the map, so if the map size == window size, that means all the entries in the map are unique, and when those numbers are not equal, there are duplicates in the window as well as the map, so start removing from the back (start position) until you eliminate the duplicates. At some point (including 0), we can see that ws = mp.size()

```c++
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
```
![WhatsApp Image 2024-12-07 at 17 04 07_865d8ca0](https://github.com/user-attachments/assets/de9f90f3-573d-43da-9290-0c5501a56f2b)

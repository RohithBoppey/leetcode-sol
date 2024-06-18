- The logic is kind of simple
- When the count is `even` -> we can add one on left, one on right => `so directly add`
- But when count is `odd` -> we can add `n - 1` as that would be even
  - This is even valid for the one where the count is `1` as we would be adding `0`
- At the end, after adding all even numbers, if there is an odd number, then we should add that in the middle

```c++
class Solution {
public:
    
    int n;
    unordered_map<char,int> mp;
    
    int longestPalindrome(string s) {
        int ans = 0;
        n = s.length();
        int flag = 0; // to check if odd is present or not
        for(auto c: s){
            mp[c]++;
        }
        for(auto [ch, fr]: mp){
            if(fr % 2 == 0){
                ans += fr;
            }else{
                ans += fr - 1;
                flag = 1;
            }
        }
        return (flag == 1) ? ans + 1 : ans;
    }
};
```

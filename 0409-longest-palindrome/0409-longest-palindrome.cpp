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
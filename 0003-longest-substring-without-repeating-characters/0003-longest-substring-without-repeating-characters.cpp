class Solution {
public:
    unordered_map<char, int> mp;

    int ws(int& i, int& j){
        return j - i + 1;
    }

    int ms(){
        return mp.size();
    }

    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0; // pointers required for traversal;
        int ans = 0;
        int n = s.size();

        while(j < n){
            cout << s[j] << endl;
            mp[s[j]]++;

            if(ws(i, j) > ms()){
                // some duplicate character is there
                while(i <= j && ws(i, j) > ms()){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        // erase
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }else{
                // no duplicates are there
                ans = max(ans, ms());
            }

            j++;

        }

        return ans;
    }
};
class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }

    int countVowelSubstrings(string s) {
        int i = 0, j = 0;
        int ans = 0;
        int n = s.size();

        if(n < 5){
            return false;
        }
        // using sliding window template
        unordered_map<char, int> mp;

        // next consonant, since we can add the vowels to the exxisiting substring before this index
        vector<int> next(n, 0);
        int last = n;
        for(int i = n - 1; i >= 0; i--){
            next[i] = last;
            // if my current one is a consonant
            if(!isVowel(s[i])){
                last = i;
            }
        }

        int nv = 0;

        while(j < n){
            // process j
            if(isVowel(s[j])){
                mp[s[j]]++;
                nv++;
            }

            // keep removing from back until you get the invalid case
            // so that in the next step, you can move forward with j
            // and all the i cases are covered

            // another check to remove the extra consonants
            while(nv != j - i + 1){
                if(isVowel(s[i])){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    nv--;
                }
                i++;
            }


            // valid condition: number of vowels should match the window size
            while(mp.size() == 5){
                // remove from back
                ans += next[j] - j;

                if(isVowel(s[i])){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    nv--;
                }

                i++;
            }

            j++;

        }


        return ans;
    }
};
class Solution {
public:
    long long ans;
    unordered_map<char, int> mp;

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u'){
            return true;
        }
        return false;
    }

    long long countOfSubstrings(string word, int k) {
        ans = 0;

        // pre computing next consonant
        int n = word.size();
        vector<int> next(n);
        int last = n;

        for(int i = n - 1; i >= 0; i--){
            // first put the value
            next[i] = last;
            if(!isVowel(word[i])){
                // and then update the value if not a vowel for the next vowel
                last = i;
            }
        }

        // using sliding window template with some modification
        int i = 0, j = 0;
        int cons = 0;

        while(j < n){
            // process j
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                cons++;
            }

            // if the cons > k, no use, so shrink until equal
            while(cons > k){
                // remove from back
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }  

            // check for the vowel condition
            while(mp.size() == 5 && cons == k){
                // vowels and cons matched
                // add the next vowel substrings using j using the pre-computed
                ans += next[j] - j;

                // since matched, should move the window forward
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }

            j++;

        }

        return ans;
    }
};
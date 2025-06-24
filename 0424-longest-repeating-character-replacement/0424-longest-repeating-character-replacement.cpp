class Solution {
public:
    vector<int> freq;

    int maxFreq(){
        int mx = 0;
        for(int i = 0; i < 26; i++){
            mx = max(mx, freq[i]);
        }
        return mx; 
    }

    int characterReplacement(string s, int k) {
        int n = s.size(); 

        // using sliding window approach to solve this problem
        // idea: move window if the number of replacements required is greater than the given limit

        int i = 0, j = 0;

        freq.resize(26, 0);
        int mx = -1;
        // always store the max freq;

        int ans = 0;

        while(j < n){
            freq[s[j] - 'A']++;
            mx = max(mx, freq[s[j] - 'A']);

            // check whether we can expand the window or else contract it from back
            if((j - i + 1) - mx <= k){
                // once max freq element is removed from window size, we should be left with number of changes required
                // if <= k can continue
                ans = max(ans, j - i + 1);
            }else{
                // start removing from behind 
                freq[s[i] - 'A']--;
                mx = maxFreq();
                i++;
            }
            j++;
        }

        return ans;

    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> possible(n + 1, 0);
        possible[n] = 1; // possible coz empty is present in all
        
        for(int i = n - 1; i >= 0; i--){
            // comparing with each word
            for(auto &word: wordDict){
                int w = word.length();
                if(w + i <= n and s.substr(i, w) == word){
                    // possible and also similar
                    possible[i] = possible[i + w];
                }
                if(possible[i] == 1){
                    // no need to check
                    break;
                }
            }
        }
        
        // for(auto x: possible){
        //     cout << x << " ";
        // }
        // cout << endl;
        
        return possible[0];
    }
};
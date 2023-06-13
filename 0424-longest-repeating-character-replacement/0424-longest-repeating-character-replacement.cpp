class Solution {
public:
    int characterReplacement(string s, int k) {
        // SLIDING WINDOW PROBLEM
        
        int n = s.size();
        
        int res = 0;
        
        int i = 0, j = 0, sz = 0, mx = 0;
        
        vector<int> freq(26, 0);
        
        while(j < n){
            freq[s[j] - 'A']++;
            mx = max(mx, freq[s[j] - 'A']);
        
            sz = j - i + 1;
            
            // checking whether we can use the current window size or not
            // LOGIC IS: if(curr - max < k) {we can use it} else {remove}
            
            if(sz - mx <= k){
                // we can use it
                res = max(sz, mx);
            }
            else{
                // we cannot use the current window size
                // need to remove from the start
                
                freq[s[i] - 'A']--;
                mx--;
                
                // find the new max;
                for(int ind = 0; ind < 26; ind++){
                    mx = max(mx, freq[ind]);
                }
                
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};
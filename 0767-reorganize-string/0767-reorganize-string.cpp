class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        
        // using this to mark max char & its freq 
        int mxFreq = 0; 
        char mxChar = 'a';
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
            if(mxFreq < freq[s[i] - 'a']){
                mxFreq = freq[s[i] - 'a'];
                mxChar = s[i];
            }
            if(freq[s[i] - 'a'] > (n + 1) / 2){
                // cannot be possible
                return "";
            }
        }
        
        // now frequency array is populated and we know the max occuring element
        // deal with that first -> fill that first
        string result = s;
        int start = 0;
        
        while(mxFreq > 0){
            result[start] = mxChar;
            start += 2;
            mxFreq--;
            freq[mxChar - 'a']--;
        }
        
        // now fill in the rest
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                // should fill
                if(start >= n){
                    // max it will be repeated just once
                    start = 1;
                }
                result[start] = (char)(i + 'a');
                start += 2;
                freq[i]--;
            }
        }
        
        return result;
    }
};
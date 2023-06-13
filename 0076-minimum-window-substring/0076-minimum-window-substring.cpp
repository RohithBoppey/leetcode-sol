class Solution {
public:
    string minWindow(string s, string t) {
        
        // we are taking a map to store the contents of the shorter string
        unordered_map<char, int> mp;
        
        string res = "";
        
        for(auto ch: t){
            mp[ch]++;
        }
        
        // map is populated
        int count = mp.size();
        
        // the entire operation works on count == 0
        int i = 0, j = 0, sz = 0, n = s.size(), minWindowSize = INT_MAX, start = 0;
        
        while(j < n){
            // check whether we have it
            if(mp.find(s[j]) != mp.end()){
                // we have it
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    // we have enough
                    count--;
                }
            }
            
            // checking whether count = 0
            
            if(count == 0){
                // all the conditions are satisfied
                // we need to minimise the given window size
                while(i < n){
                    // starting from ith position to the end
                    if(mp.find(s[i]) == mp.end()){
                        // utterly useless
                        i++;
                    }else{
                        // if negative we have extra, can safely remove
                        if(mp[s[i]] < 0){
                            mp[s[i]]++;
                            i++;
                        }else{
                            // we have >= 0
                            break;
                        }
                    }
                }
                
                // since conditions are satisfied
                sz = j - i + 1;
                
                if(sz < minWindowSize){
                    // updating the start and window size for generating string at the end
                    minWindowSize = sz;
                    start = i;
                }
                
                // we need to move i for the next positions
                mp[s[i]]++;
                count++; // definitely will increase
                i++;
                
            }
            j++;    
        }
        
        // generating string at the end
        
        if(minWindowSize != INT_MAX){
            res = s.substr(start, minWindowSize);
        }
        return res;
        
    }
};
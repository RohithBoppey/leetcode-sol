class Solution {
public:
    vector<vector<string>> ans; 
    unordered_map<string, vector<string>> mp; 

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string s; 
        for(auto &str: strs){
            int n = str.size(); 
            vector<int> curr(26, 0); 
            // populate count
            for(auto &ch: str){
                curr[ch - 'a']++;
            }
            // make the string
            s = "";
            for(int i = 0; i < 26; i++){
                if(curr[i] != 0){
                    s += to_string(i) + to_string(curr[i]) + ',';
                }
            }
            // cout << s << endl;
            // put the key in map 
            mp[s].push_back(str);
        }        

        // build final map
        for(auto &it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
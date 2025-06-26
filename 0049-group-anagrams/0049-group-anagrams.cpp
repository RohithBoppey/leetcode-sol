class Solution {
public:
    unordered_map<string, vector<string>> mp; 
    vector<vector<string>> ans; 

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(); 
        
        for(auto &x: strs){
            string y = x; 
            sort(y.begin(), y.end());
            // cout << y << endl; 
            mp[y].push_back(x);
        }

        for(auto &it: mp){
            ans.push_back(it.second);
        }

        return ans; 

    }
};
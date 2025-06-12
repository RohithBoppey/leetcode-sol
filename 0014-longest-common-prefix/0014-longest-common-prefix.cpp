class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        // first loop: letter, then: loop
        for(int i = 0; i <= strs[0].size(); i++){
            for(int j = 0; j < strs.size(); j++){
                // comparing it with the first word only
                if(i == strs[j].size() || strs[j][i] != strs[0][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }

        return res;
    }
};
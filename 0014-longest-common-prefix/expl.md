idea: 
- instead of looping over word > letter of each string, loop over letter > word
- first for loop iterates over all the letters in any arbitrary word
- second loop iterates over each string
- in the loop, since letter is fixed, I am checking all the words's ith letter with the first one
- but handle the boundary condition as well like: the first word we selected might not be the minimum word too, so if i == jth word size, return the res, as we reached the min word's end 

```c++
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
```

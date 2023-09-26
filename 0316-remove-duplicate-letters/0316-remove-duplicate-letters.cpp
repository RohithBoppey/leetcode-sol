class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string result = "";
        
        // one to store the last index
        // one to store whether the current character is seen or not
        vector<int> li(26, 0);
        vector<int> seen(26, 0);

        int ind;
        char ch;
        for(int i = 0; i < n; i++){
            ch = s[i];
            ind = ch - 'a';

            li[ind] = i;
        }

        // to populate result
        for(int i = 0; i < n; i++){
            ch = s[i];
            ind = ch - 'a';

            if(seen[ind] == 1){
                // is already there in the string
                // no use
                continue;
            }

            while(result.size() > 0 && result.back() > ch && li[result.back() - 'a'] > i){
                // that means that the character in the result is also coming again in the string
                // and also is more than the current character
                // like in bcabc -> in this bc are coming again, so the first set of bc can be removed safely
                seen[result.back() - 'a'] = 0;
                result.pop_back();
            }

            // now just add the letter and mark it as seen
            result.push_back(ch);
            seen[ch - 'a'] = 1;
        }

        return result;
    }
};
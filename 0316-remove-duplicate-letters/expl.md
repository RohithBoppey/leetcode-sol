It is all about popping if the current element is also coming afterwards and the current indexed element is smaller than the last char in the array.      
      
![image](https://user-images.githubusercontent.com/73538974/270776196-51951377-b441-437a-90b5-bb2080e110c5.png)
![image](https://user-images.githubusercontent.com/73538974/270776250-6b3ced2b-8022-4982-be55-72d7ffb1bfee.png)
![image](https://user-images.githubusercontent.com/73538974/270776267-d5e0a961-fbc5-41c3-a3e5-0ac95b3fc001.png)
![image](https://user-images.githubusercontent.com/73538974/270776305-cff6093f-1c68-4760-b4a9-540d25a12421.png)
![image](https://user-images.githubusercontent.com/73538974/270776333-6cf82ac7-03d3-40e6-8d76-68d976464829.png)
      
```
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
```

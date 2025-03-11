![image](https://github.com/user-attachments/assets/d4550100-60c8-4753-a298-e363459fdd00)

```c++
class Solution {
public:

    int ans;
    unordered_map<char, int> mp;

    int numberOfSubstrings(string s) {
        int n = s.size();
        ans = 0;

        if(s.size() < 3){
            // cannot form a valid string
            return 0;
        }

        int i = 0, j = 0;

        while(j < n){

            // process j
            char ch = s[j];
            mp[ch]++;
            
            // if valid
            // keep processing from behind until invalid
            // valid condn: minimum all special chars abc should be there
            while(mp.size() == 3){
                // from behind
                // for a certain substring, how many more elements from the right can we include in the current substring
                // in this case, all the right of j elements can be added since already we have condition met
                ans += n - j;

                // remove the first letter from behind 
                // change in map if special character
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    // remove
                    mp.erase(s[i]);
                }
                
                i++;
            }
            j++;
        }


        return ans;
    }
};
```

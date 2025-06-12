Ways to solve this: 
- maintain count of letters in both and check
- sort and equate

```c++
class Solution {
public:
    void printV(vector<int>& v){
        for(auto &x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    bool isAnagram(string s, string t) {
        // taking count
        if(s.size() != t.size()){
            return false;
        }

        int l = s.size();
        vector<int> s1(26, 0), s2(26, 0);

        for(int i = 0; i < l; i++){
            s1[s[i] - 'a']++;
            s2[t[i] - 'a']++;
        }

        // printV(s1);
        // printV(s2);

        for(int i = 0; i < 26; i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }


        return true;
    }
};
```​

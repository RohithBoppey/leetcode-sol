

Sliding window template problems: https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template!/
Once all problems are done, come back to this problem: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10

Sliding window template: 
In this case - https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1, the window size is the same: given pattern, so when the window size is met, we are just proceeding forward, if not matched, do nothing. 
- If not matched, do nothing
- if matched, check for the condition, and move forward by moving left
- since, outside anyways right is there, after 2. the window has moved forward now

```c++
// User function template for C++
class Solution {
  public:
    
    unordered_map<char, int> m1, m2;
  
    bool check(string& pat){
        for(char ch: pat){
            if(m1[ch] != m2[ch]){
                // not matching
                return false;
            }
        }
        return true;
    }
  
    int search(string &pat, string &t) {
        // code here
        
        int ans = 0;
        // use m1 for the input string
        for(auto ch: pat){
            m1[ch]++;
        }
        
        // use m2 for the sliding window
        int low = 0, high = 0, n = t.size();
        
        while(high < n){
            // process high
            char ch = t[high];
            m2[ch]++;
            
            // check for the window size
            if(high - low + 1 == pat.size()){
                // check and move the window
                if(check(pat) == true){
                    ans++;
                }
                // now increase i to move ahead
                m2[t[low]]--;
                low++;
            }
            high++;
        }
        return ans;
    }
};
```

Sliding window template problems: https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template!/
Once all problems are done, come back to this problem: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10

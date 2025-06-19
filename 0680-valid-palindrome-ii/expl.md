- at any point, if it is a palindrome, we need not touch it, hence return true at the end
- if not a palindrome, that means in the left, right pointer, one at the start, one at the end, they might not be matching
- hence make 2 substrings (or check with index) like [left + 1, right] and [left, right - 1] -- if these 2 are palindromes, that means we can remove at most one letter to make it a palindrome
- if these 2 are also false, that means: even if you remove one, it is not a palindrome, return false

```c++
class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        int n = s.size(); 
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        // doing o(N2) solution
        int n = s.size(); 

        string lefts, rights;
        int left = 0, right = n - 1;
        // at any point, you can only remove one character, so use pointers to narrow down to which element to remove
        while(left < right){
            if(s[left] != s[right]){
                // check in both the cases
                return (isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1));
            }
            left++;
            right--;
        }

        return true;
    }
};
```

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
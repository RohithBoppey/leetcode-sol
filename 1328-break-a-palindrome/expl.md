​Asked in google (variation) and amazon        
        
![WhatsApp Image 2023-07-17 at 13 01 57](https://user-images.githubusercontent.com/73538974/253877699-3018c859-3258-4b43-b9e3-779a414201ee.jpg)
        
        
```
class Solution {
public:
    string breakPalindrome(string s) {
        
        // given s is the palindrome
        int n = s.size();
        
        if(n == 1){
            // no way we can replace it
            return "";
        }
        
        // replacing with lexagraphic smallest one -> a
        
        for(int i = 0; i < n / 2; i++){
            // if some letter is not a, we can quietly replace it
            if(s[i] != 'a'){
                s[i] = 'a';
                return s;
            }
        }
        
        
        // if you have reached here
        // this means that first half n / 2 letters are all 'a'
        // since this is a palindrome, last n / 2 letters should also be 'a'
        
        // something like: "aaaa" or "aabaa"

        // so the next solution is convering the last letter to "b"
        
        s[n - 1] = 'b';
        return s;
        
    }
};
```

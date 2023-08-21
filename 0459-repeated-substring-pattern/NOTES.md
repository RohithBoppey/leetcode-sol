​Somehow we need to find the pattern repeating, and if it is repeating, then true. Else false.     
The idea can be generated with since it is always repeating from a substring -> we can say that the substring length has to be a factor of the length of actual given string.       
For example = "abcabcabcabc" -> the possible factors are: 1,2,3,4,6 (Note that the 12 itself cannot be considered as factor)      
So for each factor if we are able to make sure that the window contains the same letter, we are done.     
Here in this case, we can see that for "3" -> the condition satisfies.

![WhatsApp Image 2023-08-21 at 16 27 01](https://user-images.githubusercontent.com/73538974/262002862-bf73d1d5-2154-4c4c-a04a-5e426e4ab0ba.jpg)

CODE:       
```
class Solution {
public:
    
    void findFactors(int n, vector<int>& factors){
        int a, b;
        factors.push_back(1);
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                // is divisble, check for square root
                a = i;
                b = n / i;
                factors.push_back(a);
                if(a != b){
                    factors.push_back(b);
                }
            }
        }
    }
    
    void printVector(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n == 1){
            // cannot form a substring
            return false;
        }
        // should find factors for the length now
        vector<int> factors;
        findFactors(n, factors);
        // printVector(factors);
        // for each factor, check if all the strings are same
        int fa, j;
        for(int i = 0; i < factors.size(); i++){
            fa = factors[i];
            j = fa;
            for(; j < n; j++){
                if(s[j] != s[j % fa]){
                    break;
                }
            }
            // here it either breaks or the loop is done
            // if loop is done, that means it is true
            if(j == n){
                return true;
            }
        }
        return false;
    }
};
```

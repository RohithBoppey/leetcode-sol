ASKED IN GOOGLE, ORACLE AND TCS
      
Making string and solving will most likely give a MLE, so this is better approach:      
        
![image](https://user-images.githubusercontent.com/73538974/270916009-22ef8e5f-6954-4cfa-b990-38ec801b9fa5.png)
![image](https://user-images.githubusercontent.com/73538974/270916073-39b93780-31b0-4a3e-b7a6-ef5443435a92.png)
![image](https://user-images.githubusercontent.com/73538974/270916118-9eaa5367-0c66-41b8-90f4-8a82793c6ad3.png)
    
```
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // since constructing string might give us memory limit exceeded
        int n = s.size();
        long long int len = 0, ind;
        char ch;

        string result = "";

        for(int i = 0; i < n; i++){
            ch = s[i];
            if(ch >= 'a' && ch <= 'z'){
                // is a char
                len++;
            }else{
                // is a number
                ind = ch - '0';
                len *= ind;
            }
        }

        // now start from behind and find until k == 0
        for(int i = n - 1; i >= 0; i--){
            ch = s[i];
            k = k % len;
            if(k == 0 && isalpha(ch)){
                result +=  ch;
                return result;
            }
            if(ch >= 'a' && ch <= 'z'){
                len--;

            }else{
                ind = ch - '0';
                len /= ind;
            }
        }

        return "";
    }
};
```

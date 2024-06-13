![image](https://user-images.githubusercontent.com/73538974/269843451-40530dcd-a25e-4194-984b-c9ec1dae0be3.png)
      
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        
        int p1 = 0, p2 = 0;
        
        while(p1 < n1){
            while(p2 < n2 && s[p1] != t[p2]){
                p2++;
            }
            if(p2 == n2){
                // reached the end
                return false;
            }else{
                p2++;
            }
            p1++;
        }
        
        return true;
        
    }
};
```
      
Simpler Solution:   
      
![image](https://user-images.githubusercontent.com/73538974/269844515-49aeb952-f752-4b49-816a-23194c69049f.png)
      
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        
        int p1 = 0, p2 = 0;
        
        while(p1 < n1 && p2 < n2){
            if(s[p1] == t[p2]){
                // both matched
                p1++;
                p2++;
            }
            
            else{
                // not matched
                p2++;
            }
        }
        
        return (p1 == n1) ? true: false;
        
    }
};
```​

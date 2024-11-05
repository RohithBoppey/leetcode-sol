Editing these test cases: 
  
```
[1,2,3]
[1,1]
[1,2]
[1,2,3]
[1,2,4,1,2,3]
[1,1,3,5,4]
[1,3,3,4,5]
[1,1,2,2,3,4]
```

```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int stud = g.size();
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        // greed(students satisfied) pointer and size(cookie) pointer
        int left = 0, right = 0;
        
        // either all students are done and cookies are left - case 1
        // or all cookie size is compared and done and students are left off (meaning only some of the students are satisfied)
        
        while(left < stud && right < n){
            if(s[right] >= g[left]){
                left++;
            }
            right++;
        }
        
        return left;
    }
};
```

This solution will give you TLE => O(N²) => 31/364 ✅    
![image](https://gist.github.com/assets/73538974/0b80cad1-a181-4f3c-8da5-1923365917d6)    
```
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int z = 0, o = 0;
            for(int j = i; j < n; j++){
                nums[j] == 0 ? z++ : o++;
                ans = (z == o) ? max(ans, 2*z) : ans;
            }
            
        }
        return ans;
    }
};
```

![image](https://github.com/user-attachments/assets/61664883-2b95-46a1-abf8-5a8798a87acd)

```c++
class Solution {
public:

    void printV(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int k = queries.size();
        vector<bool> res(k, 0);

        int n = nums.size();
        vector<int> p(n, 0);
        vector<int> sol(n, 0);
        
        for(int i = 0; i < n; i++){
            p[i] = nums[i] % 2;
        }

        sol[n - 1] = n - 1;
        for(int i =  n - 2; i >= 0; i--){
            if(p[i] == p[i+1]){
                sol[i] = i;
            }else{
                sol[i] = sol[i + 1];
            }
        }

        // printV(p);
        // printV(sol);

        int start, target;
        for(int i = 0; i < k; i++){
            start = queries[i][0];
            target = queries[i][1];
            
            res[i] = (sol[start] >= target) ? true : false;
        }

        return res;
    }
};
```

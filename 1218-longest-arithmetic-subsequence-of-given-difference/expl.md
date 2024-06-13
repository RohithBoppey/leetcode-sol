​ASKED IN: FACEBOOK AMAZON   
    
simple direct backtracking solution: 34/39 passes ✅   

![WhatsApp Image 2023-07-14 at 21 51 11](https://user-images.githubusercontent.com/73538974/253623946-4ce2ce88-9f86-40b2-b3ba-70afc4e18533.jpg)

```
class Solution {
public:
    
    void solve(vector<int>& arr, int start, vector<int>& curr, vector<vector<int>>& res, int k, int n){
        
        if(start >= n){
            res.push_back(curr);
            return;
        }
        
        int sz = curr.size();
        
        if(sz == 0 || arr[start] - curr[sz - 1] == k){
            // the thing is either empty or difference is matching
            curr.push_back(arr[start]);
            solve(arr, start + 1, curr, res, k, n);
            curr.pop_back();
        }
        
        // we can skip if we wamt
        solve(arr, start + 1, curr, res, k, n);
        
    }
    
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        
        vector<int> curr;
        
        vector<vector<int>> res;
        
        // using dp
        
        solve(arr, 0, curr, res, difference, n);
        
        int mx = 0, sz;
        
        for(auto &it: res){
            sz = it.size();
            mx = max(mx, sz);
        }
        
        return mx;
    }
};
```

RECURSION + MEMOIZATION SOLUTION:   34/39 passes ✅ 
      
```
class Solution {
public:
    
    int t[100001];
    
    int solve(vector<int>& arr, int i, int k){
        
        // we took index -> i
        
        if(t[i] != -1){
            return t[i];
        }
        
        int result = 0, n = arr.size();
        for(int j = i + 1; j < n; j++){
            if(arr[j] - arr[i] == k){
                // difference is matching
                result = max(result, 1 + solve(arr, j, k));
            }
        }
        
        return t[i] = result;
        
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        // recursion + memoization
        int n = arr.size();
        memset(t, -1, sizeof(t));
        int result = 0;
        
        // since start can be anywhere
        for(int i = 0; i < n; i++){
            // should take
            result = max(result, 1 + solve(arr, i, difference));
        }
        
        return result;
        
    }
};
```
      
Now comes the easiest solution: Using hashmap to solve it  39/39 passes ✅       
      
![WhatsApp Image 2023-07-14 at 22 48 10](https://user-images.githubusercontent.com/73538974/253635869-fc015559-287c-4849-826e-6b54f8a62d0b.jpg)     
      
```
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // using hashmap to store what are the previous difference
        unordered_map<int, int> mp;
        
        int n = arr.size();
        
        int result = 0;
        
        for(int i = 0; i < n; i++){
            int prev_len = mp[arr[i] - difference];
            mp[arr[i]] = prev_len + 1;
            result = max(result, mp[arr[i]]);
        }
        
        return result;
        
    }
};
```


​172/176 solution ✅ (TLE) Might be something wrong with how we are using strings and comparing existence

```
class Solution {
public:
    
    void toString(string& s, vector<int> curr){
        sort(curr.begin(), curr.end());
        for(int i = 0; i < curr.size(); i++){
            s += curr[i] + '0';
            s += '_';
        }
    }
    
    void solve(vector<int>& candidates, int target, int ind, int n, vector<vector<int>>& result, vector<int>& curr, unordered_map<string, int>& visited){
        
        if(target == 0){
            
            // if the current thing is not there only then push it
            string s = "";
            toString(s, curr);
            
            if(visited.find(s) == visited.end()){
                // not there
                result.push_back(curr);
                visited[s]++;
            }
            
            return;
        }
        
        if(ind >= n){
            // nothing can be done
            return;
        }
        
        
        if(target < 0){
            return;
        }
        
        // for each call, we can take it or not take it
        
        // not taking it
        solve(candidates, target, ind + 1, n, result, curr, visited);
        
        // take it
        curr.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], ind + 1, n, result, curr, visited);
        curr.pop_back();
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        
        vector<vector<int>> result;
        vector<int> curr;
        
        sort(candidates.begin(), candidates.end());
        
        unordered_map<string, int> visited;
        
        solve(candidates, target, 0, n, result, curr, visited);
        return result;
        
    }
};
```
    
172/176 solution ✅      
So instead of string operations and checking, we can simply check in a while loop to skip the duplicates      
      
```
class Solution {
public:
    
    void solve(vector<int>& candidates, int target, int ind, int n, vector<vector<int>>& result, vector<int>& curr){
        
        if(target == 0){
            result.push_back(curr);
            return;
        }
        
        if(ind >= n){
            // nothing can be done
            return;
        }
        
        
        if(target < 0){
            return;
        }
        
        // for each call, we can take it or not take it
        
        // take it
        curr.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], ind + 1, n, result, curr);
        curr.pop_back();
        
        // then skip the duplicates
        // skipping the duplicates
        int t = candidates[ind];
        
        while(ind < n && candidates[ind] == t){
            ind++;
        }
        
        // not taking it
        solve(candidates, target, ind, n, result, curr);
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        
        vector<vector<int>> result;
        vector<int> curr;
        
        sort(candidates.begin(), candidates.end());
                
        solve(candidates, target, 0, n, result, curr);
        return result;
        
    }
};
```

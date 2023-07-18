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
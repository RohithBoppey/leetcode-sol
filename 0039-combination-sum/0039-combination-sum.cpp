class Solution {
public:
    
    void solve(vector<int>& candidates, int target, int ind, int n, vector<vector<int>>& result, vector<int>& curr){
        
        if(ind >= n){
            // nothing can be done
            return;
        }
        
        if(target == 0){
            result.push_back(curr);
            return;
        }
        
        if(target < 0){
            return;
        }
        
        // for each call, we can take it or not take it
        
        // take it
        curr.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], ind, n, result, curr);
        curr.pop_back();

        
        // not taking it
        solve(candidates, target, ind + 1, n, result, curr);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        
        vector<vector<int>> result;
        vector<int> curr;
        
        solve(candidates, target, 0, n, result, curr);
        return result;
    }
};
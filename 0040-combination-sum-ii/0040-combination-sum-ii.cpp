class Solution {
public:
    int n; 
    vector<vector<int>> ans; 

    void solve(vector<int>& v, int target, int start, vector<int>& curr){
        if(target == 0){
            // the curr should be added to the ans
            ans.push_back(curr);
            // no other elements should be added
            return; 
        }

        if(start >= n){
            // cant do anything
            return;
        }

        // proceed if the current element is less than the target
        if(target >= v[start]){
            // can be added
            curr.push_back(v[start]);
            solve(v, target - v[start], start + 1, curr);
            curr.pop_back();
        }

        // if we are not taking the element, we should not take duplicates as well
        int t = v[start];
        while(start < n && v[start] == t){
            start++;
        }

        // not taking
        solve(v, target, start, curr);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> curr; 

        // sorting coz we want to remove duplicates
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, curr);

        return ans; 
    }
};
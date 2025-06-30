class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int n, int k, int start){

        if(curr.size() == k){
            // reached the limit
            ans.push_back(curr);
            return;
        }

        if(start > n){
            // nothing left to do
            return;
        }
        
        // now at any point, can take the current n value or not
        solve(n, k, start + 1);
        
        curr.push_back(start);
        solve(n, k, start + 1);
        curr.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        solve(n, k, 1);
        return ans; 
    }
};
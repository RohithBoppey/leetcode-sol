​Easy recursion solution but along with that hashing solution using Strings!

```
class Solution {
public:
    
    void toNumString(string &s, vector<int> curr){
        sort(curr.begin(), curr.end());
        for(int i = 0; i < curr.size(); i++){
            s += curr[i] + '0';
            s += '_';
        }
    }
    
    void solve(vector<int>& nums, unordered_map<string, int>& visited, int ind, vector<int>& curr, vector<vector<int>>& result, int n){
        
        if(ind >= n){
            // reached the end
            // check if the string exisits
            string s = "";
            toNumString(s, curr);
            
            cout << s << endl;
            
            if(visited.find(s) == visited.end()){
                // not there
                result.push_back(curr);
                visited[s]++;
            }
            return;
        }
        
        
        // can take or cannot take
        
        // take
        curr.push_back(nums[ind]);
        solve(nums, visited, ind + 1, curr, result, n);
        curr.pop_back();
        
        // not taking
        solve(nums, visited, ind + 1, curr, result, n);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // using another hashmap to find if the current thing is there or not
        unordered_map<string, int> visited;
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> curr;
        solve(nums, visited, 0, curr, result, n);
        return result;
        
    }
};
```

Different solution using sort and having a visited kind of array:
![image](https://user-images.githubusercontent.com/73538974/254173712-400dcf3a-54d0-4ff4-818b-602276911c3d.png)


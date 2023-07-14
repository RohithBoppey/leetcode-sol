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
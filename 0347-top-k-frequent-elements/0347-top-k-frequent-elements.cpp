class Solution {
public:

    unordered_map<int, int> mp;
    map<int, vector<int>, greater<int>> fmp; 

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<int> ans; 
        
        // now construct the frequency -> elements array
        // using bucket sort but with the counts
        // min count of each can be 0, and max is all elements same -> n
        vector<vector<int>> freq(n + 1, vector<int>(0, 0));

        for(auto &it: mp){
            freq[it.second].push_back(it.first);
        }

        for(int i = n; i >= 0; i--){
            for(auto &it: freq[i]){
                if(k < 1){
                    // top k removed
                    return ans;
                }
                ans.push_back(it);
                k--;
            }
        }

        return ans;
    }
};
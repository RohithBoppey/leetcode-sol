class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> v(n + 1, 0); // this is to measure freq;
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            v[nums[i]]++;
            if(v[nums[i]] == 2){
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};
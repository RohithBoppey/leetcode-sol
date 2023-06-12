class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        
        if(n == 0){
            return res;
        }
        
        if(n == 1){
            res.push_back(to_string(nums[0]));
            return res;
        }
        
        if(n == 2){
            if(nums[1] == nums[0] + 1){
                res.push_back(to_string(nums[0]) + "->" + to_string(nums[1]));
            }else{
                res.push_back(to_string(nums[0]));
                res.push_back(to_string(nums[1]));
            }
            return res;
        }
        
        string s;
        
        int l, r;
        for(int l = 0; l < n; l++){
            r = l;
            while(r < n - 1 && nums[r + 1] == nums[r] + 1){
                // valid
                r++;
            }
            
            if(r > l){
                // more than one ele
                s = to_string(nums[l]) + "->" + to_string(nums[r]);
            }else{
                // just one element
                s = to_string(nums[l]);
            }
            
            res.push_back(s);
            l = r;
        }
        
        return res;
    }
};
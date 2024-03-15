class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, np = 1, allZero = 1, nz = 0;
        int n = nums.size();
        for(auto x: nums){
            product *= x;
            if(x != 0){
                np *= x;
                allZero = 0;
            }else{
                nz++;
            }
        }
        
        if(allZero == 1){
            // all are zeroes
            return vector<int>(n, 0);
        }
        
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(nz == 1){
                    // only this is the zero
                    res[i] = np;
                }else{
                    res[i] = 0;
                }
            }else{
                res[i] = product / nums[i];
            }
        }
        return res;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 

        int cmx = 1, cmn = 1, curr = 1, res = 0; 
        
        if(n == 1){
            return nums[0];
        }

        for(int i = 0; i < n; i++){
            curr = nums[i];
            int val = cmx * curr;
            cmx = max(max(val, cmn * curr), curr);
            cmn = min(min(val, cmn * curr), curr);

            // now populate the ans
            res = max(res, cmx); 
        }

        return res; 


    }
};
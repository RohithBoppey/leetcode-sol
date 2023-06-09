class Solution {
public:
    int max1(int a, int b, int c){
        return max(max(a, b), c);
    }
    
    int min1(int a, int b, int c){
        return min(min(a, b), c);
    }
    
    int maxProduct(vector<int>& nums) {
        int local_max = 1, local_min = 1, global_max = 0;
        int n = nums.size();
        
        if(n == 1){
            return nums[0]; 
        }
        
        for(int i = 0; i < n; i++){
            int temp = local_max * nums[i];
            local_max = max1(local_max * nums[i], local_min * nums[i], nums[i]);
            local_min = min1(temp, local_min * nums[i], nums[i]);

            global_max = max(global_max, local_max);
        }
        
        return global_max;
    }
};
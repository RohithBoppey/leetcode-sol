class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // the idea is to find the next permutation new
        
        // from behind, finding the required position
        int req_pos = -1;
        
        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                // found
                req_pos = i - 1;
                break;
            }
        }
        
        
        if(req_pos != -1){
            int swap_index = req_pos;
        
            // finding the next greater element from the end starting from req_os + 1
            for(int i = n - 1; i >= req_pos + 1; i--){
                if(nums[i] > nums[req_pos]){
                    // found swap index
                    swap_index = i;
                    break;
                }
            }

            // swap both the indices
            swap(nums[swap_index], nums[req_pos]);
        }
        
        
        // from the req_pos + 1, reverse the rest
        reverse(nums.begin() + req_pos + 1, nums.end());
        
    }
};
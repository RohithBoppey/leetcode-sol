class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // we need 4 pointers
        int i, j, k, l;
        
        long long int sum;
        
        // sort the array
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < n; i++){
            // skip duplicates after the first element
            if(i > 0 && nums[i] == nums[i - 1]){
                // same as prev
                continue;
            }
            
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    // same as prev
                    continue;
                }
                
                // i and j are standing at unique pos
                // use the other 2 pointers to find the sum
                
                k = j + 1;
                l = n - 1;
                
                // k and l are low and high
                
                while(k < l){
                    // find sum and verify
                    sum = (long long int) nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if(sum == target){
                        // found the pair
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        // update the low and high accordingly
                        while(k < l && nums[k] == nums[k + 1]){
                            k++;
                        }
                        
                        while(k < l && nums[l] == nums[l - 1]){
                            l--;
                        }
                        
                        // since we found the sum
                        k++;
                        l--;
                        
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                    
                }
            }
            
        }
        return result;
    }
};
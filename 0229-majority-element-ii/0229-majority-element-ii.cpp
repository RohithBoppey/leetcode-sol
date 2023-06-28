class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        // using the concept of mooore's but using 2 variables
        // since max there can only be 2
        
        int c1 = 0, c2 = 0, e1 = INT_MIN, e2 = INT_MIN;
        
        for(int i = 0; i < n; i++){
            // since both elements cant be equal
            if(c1 == 0 && e2 != nums[i]){
                c1 = 1;
                e1 = nums[i];
            }else if(c2 == 0 && e1 != nums[i]){
                c2 = 1;
                e2 = nums[i];
            }
            // new
            // now that c1 != 0 and c2 != 0
            else if(e1 == nums[i]){
                c1++;
            }
            else if(e2 == nums[i]){
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        
        // now that we found top repeating 2 elements, we are verifying
        int t1 = 0, t2 = 0;
        
        for(int i = 0; i < n; i++){
            if(e1 == nums[i]){
                t1++;
            }
            if(e2 == nums[i]){
                t2++;
            }
        }
        
        // now that count is populated, check and push
        int req = (n / 3) + 1;
        
        if(t1 >= req){
            result.push_back(e1);
        }
        if(t2 >= req){
            result.push_back(e2);
        }
        return result;
    }
};
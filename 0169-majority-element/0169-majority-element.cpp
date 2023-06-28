class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // new
        // using the moore's voting algorithm - to find the majority element
        int count = 0, ele = 0;
        
        for(int i = 0; i < n; i++){
            if(count == 0){
                count++;
                ele = nums[i];
            }else if(ele == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        
        // since it is given for sure that such an element exists
        return ele;
    }
};
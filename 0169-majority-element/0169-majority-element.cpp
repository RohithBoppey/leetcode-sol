class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using the moore's voting algorithm 
        int count = 0, element = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(element == nums[i]){
                count++;
            }else{
                count--;
                count = (count < 0) ? 0 : count;
            }

            if(count == 0){
                // change the number
                count = 1;
                element = nums[i];
            }
            
        }

        return element;

    }
};
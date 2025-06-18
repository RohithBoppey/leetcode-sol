class Solution {
public:
    int n;
    int removeElement(vector<int>& nums, int val) {
        n = nums.size();
        int i = 0, j = 0; 
        while(j < n){
            if(nums[j] != val){
                // replace it with the current i
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
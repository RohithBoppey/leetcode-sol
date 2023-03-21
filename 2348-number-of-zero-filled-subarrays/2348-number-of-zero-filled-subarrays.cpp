class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // find the consecutive ranges of i and j
        // something like a window
        // then we can have len = j - i + 1
        // and possible combinations = len * (len + 1) / 2
        // add it to total 
        // return total
        
        long long total = 0, len = 0;
        int n = nums.size(); // in the number range only, so len
        int i = 0, j = 0;
        while(i < n && j < n){
            if(nums[i] != 0){
               i++;
            }else{
//                 == 0
//                 find the j from i upto where there are consecutive zeroes
                j = i;
                while(j < n && nums[j] == 0){
                    j++;
                }
//                 length is from i to j - 1
                len = j - i;
                total += (len * (len + 1)) / 2;
                i = j;
            }
        }
        
        return total;
    }
};
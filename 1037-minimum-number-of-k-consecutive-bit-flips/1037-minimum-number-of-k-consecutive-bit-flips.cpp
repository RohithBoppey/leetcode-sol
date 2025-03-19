class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();

        // using number instead of array
        int flipCount = 0;
        vector<int> flips(n, 0);
        
        int tf = 0; //total flips

        int i = 0;
        while(i < n){
            // check the influence and adjust the flipCount for the certain i
            if(i >= k){
                // subarray found
                if(flips[i - k] == 1){
                    // now at this point, influence has vanished, and we are having one extra 
                    // so reduce 1
                    flipCount--;
                }
            }


            // check and do the flip
            if(
                (nums[i] == 0 && flipCount % 2 == 1) 
                || 
                (nums[i] == 1 && flipCount % 2 == 0)
            ){
                // no need of flipping
                i++;
            }else{
                // boundary condition
                if(i > n - k){
                    // cannot flip
                    return -1;
                }

                // we need to flip the k-size window
                tf++;
                flipCount++;

                // mark in flips
                flips[i] = 1;

                i++;
            }
        }

        return tf;

    }
};
class Solution {
public:
    int n;

    void sortColors(vector<int>& nums) {
        n=nums.size();
        int i=0, j=0, k=n-1;

        // j is the current looper in the array
        while(j<=k){
            if(nums[j]==0){
                // 0 to i-1 should be 0, swap with i
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else if(nums[j]==1){
                j++;
            }else{
                // k
                // since k+1 to j everything should be 2
                swap(nums[j],nums[k]);
                k--;
            }
        }

        return;
    }
};
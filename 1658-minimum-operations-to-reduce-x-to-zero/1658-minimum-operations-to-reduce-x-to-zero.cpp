class Solution {
public:
    
    // this function will return the minLength of the subarray, which equates to the sum
    int solve(vector<int>& v, int sum){
        int n = v.size();
        int mn = 0;

        int i = 0, j = 0;
        int csum = 0;

        while(j < n){
            csum += v[j];

            if(csum > sum){
                // reduce until less
                while(i < j && csum > sum){
                    csum -= v[i];
                    i++;
                }
            }


            if(csum == sum){
                // find min
                mn = max(mn, j - i + 1);
            }

            j++;

        }

        return mn;
    }
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        // find totalSum;
        int totalSum = 0;
        
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        
        if(totalSum == x){
            // all has to be considered
            return n;
        }
        
        // find maxSubarray with sum - x len
        int sum = totalSum - x;
        
        int len = solve(nums, sum);
        
        // cout << len << endl;
        
        if(len == 0){
            // no subarray found
            return -1;
        }
        
        return n - len;
        
    }
};
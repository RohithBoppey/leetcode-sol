class Solution {
public:

    int n;
    int solve(vector<int>& v, int sum){
        int divs = 1;
        long curr = 0;

        for(int i = 0; i <n; i++){
            curr += v[i];
            if(curr > sum){
                // should break the array
                divs++;
                curr = v[i];
            }
        }

        return divs;
    }

    int splitArray(vector<int>& nums, int k) {
        
        n = nums.size();

        // we are selecting the range for the max sum that can be obtained from a subarray
        // so min is max(arr) because we are breaking all the elements as single and max of sums would be max(arr), max is sum(arr)

        int low = INT_MIN, high = 0;
        for(auto &x: nums){
            low = max(low, x);
            high += x;
        }

        int mid;
        while(low < high){
            mid = low + (high - low) / 2;

            // max number of divisions that can be obtained if the max sum is mid
            int divs = solve(nums, mid);

            if(divs > k){
                // we must definitely increase the max sum that is obtained, so that number of divs are reduced, even this sum is unacceptable
                low = mid + 1;
            }
            else{
                // k is getting satisfied, but still the sum can be reduced (as per the question), but this is also satisfied
                high = mid;
            }

        }

        return low;
    }
};
class Solution {
public:

    int giveSum(vector<int>& v, int d){
        int sum = 0, r;
        for(auto &x : v){
            sum += x / d;
            r = x % d;
            sum += (r) ? 1 : 0;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();

        int low = 1, high = 1000001;
        int mid;
        while(low < high){
            mid = low + (high - low) / 2;
            int sum = giveSum(nums, mid);

            if(sum <= t){
                // this divisor is acceptable, but the sum can be increased -> divisor can be decreased
                high = mid;
            }else{
                // sum > t
                // *not acceptable* -> must reduce the sum -> increase the divisor
                low = mid + 1;
            }
        }

        return high;

    }
};
class Solution {
public:
    int mySqrt(int t) {
        
        if(t <= 1){
            return t;
        }
        
        // using binary search to solve this
        int low = 1, mid, high = t / 2;

        while(low <= high){
            mid = low + (high - low) / 2;

            long long val = (long long) mid * mid;

            if (val == (long long)(t)){
                // found sqrt
                return mid;
            }
            else if(val < (long long)(t)){
                // increase search space
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return high;

    }
};
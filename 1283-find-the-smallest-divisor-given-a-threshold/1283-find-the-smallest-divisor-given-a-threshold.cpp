class Solution {
public:
    long long int solve(vector<int>& nums, int k){
        long long int sum = 0;
        for(auto x: nums){
            sum += (x % k == 0) ? x / k : (x / k) + 1;
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid;
        int minDiv = INT_MAX;
        long long int sum;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            sum = solve(nums, mid);
            
            if(sum > threshold){
                // sum has to reduce -> divisor has to increase
                low = mid + 1;
            }else{
                // already condition is meeting here
                // sum has to increase -> divisor has to reduce
                minDiv = mid;
                high = mid - 1;
            }
            
        }
        
        return minDiv;
    }
};
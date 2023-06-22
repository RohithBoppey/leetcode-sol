class Solution {
public:
    
    long long int solve(vector<int>& candies, int n){
        // return the number of children that we can feed if each pile contains n candies 
        
        long long int ans = 0;
        for(auto pile: candies){
            ans += pile / n;
            // less than pile means automatically zero
        }
        
        return ans;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        // we need to find max number of candies a child can get
        
        // min number of candies is 1 and max is max(candies)
        
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int mid;
        
        // with the help of low and high, we try to find the max number of candies that can feed the k children
        
        int ans = INT_MIN;
        
        long long int n = 0;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            n = solve(candies, mid);
            
            if(n >= k){
                // we are feeding more children than required
                // so now we need to increase candy count to each children
                ans = max(ans, mid);
                low = mid + 1;
            }else{
                // we are not able to feed the desired amount of children
                // so we need to reduce candy count
                high = mid - 1;
            }
        }
        
        return ans == INT_MIN ? 0 : ans;
        
    }
};
class Solution {
public:
    long long int solve(vector<int>& quantities, int k){
        long long int result = 0;
        for(auto p: quantities){
            result += (p % k == 0) ? (p / k) : (p / k) + 1;
        }
        return result;
    }
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        // should divide the product quantities into n shops
        // each shop should get max amount of products
        
        int low = 1, high = *max_element(begin(quantities), end(quantities));
        
        if(n == quantities.size()){
            return high;    
        }
        
        int mid;
        int ans = INT_MIN;
        long long int shopsCovered;
        
        // we are checking how many shops it can cover and based on that
        while(low <= high){
            mid = low + (high - low) / 2;
            shopsCovered = solve(quantities, mid);
            if(shopsCovered > n){
                // we are covering more shops than needed
                // so we can increase the number of products for each shop
                low = mid + 1;
            }else{
                // we are covering less shops than needed
                // decrease the number of prodcts for each shop
                ans = mid;
                high = mid - 1;
            }
        }
        
        
        return ans;
    }
};
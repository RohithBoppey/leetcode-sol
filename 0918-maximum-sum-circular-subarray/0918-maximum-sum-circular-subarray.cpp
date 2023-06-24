class Solution {
public:
    // new
    int n;
    int kadanesMax(vector<int>& nums){
        // this function returns the max sum of an array in O(N)
        int csum = 0;
        int msum = nums[0];
        
        for(int i = 0; i < n; i++){
            csum += nums[i];
            msum = max(msum, csum);
            csum = (csum < 0) ? 0 : csum;
        }
        
        return msum;
        
        // O(N) SOLUTION
    }
    
    int kadanesMin(vector<int>& nums){
        // this function returns the min sum of an array in O(N)
        int csum = nums[0];
        int msum = nums[0];
        
        for(int i = 1; i < n; i++){
            csum = min(csum + nums[i], nums[i]);
            msum = min(csum, msum);
        }
        
        return msum;
        
        // O(N) SOLUTION
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        n = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        mx = kadanesMax(nums);
        
        // finding the min sum
        int total = 0;
        
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        
        // total sum is now populated
        mn = kadanesMin(nums);
        
        cout << mx << " " << mn << endl;
        
        int csum = total - mn;
        
        return (mx > 0) ? max(mx, csum) : mx;
    }
};
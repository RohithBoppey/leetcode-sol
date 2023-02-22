class Solution {
public:
    int left, right, curr, mid, d, ans;
    
    int shipWithinDays(vector<int>& weights, int days) {
//         creating n bin with proper bin size
//         max size = sum(weights) in 1 day
//         min size = max(weights) in some days
//         so bounds are [max(weights), sum(weights)]
        left = 0; right = 0;
        for(auto w: weights){
            left = max(left, w);
            right += w;
        }
        // cout << left << " " << right << endl;
        
        int i = 0, n = weights.size(), ans = INT_MAX;
        
        while(left <= right){
            curr = 0;
            d = 1;
            mid = left + (right - left) / 2;
//             we are finding the number of partitions
            i = 0;
            while(i < n && curr <= mid){
                curr += weights[i];
                i++;
                if(curr > mid){
//                     making a partition
                    i--;
                    curr = 0;
                    d++;
                }
            }
            
            if(d > days){
                left = mid + 1;
            }else{
//                 d <= days
                ans = min(ans, mid);
                right = mid - 1;
            }
        }
        
        return ans;
    }
};
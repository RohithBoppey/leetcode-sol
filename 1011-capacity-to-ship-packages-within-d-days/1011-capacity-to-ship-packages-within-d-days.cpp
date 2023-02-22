class Solution {
public:
    int low, high, mid, ans, i, curr, d;
    
    int shipWithinDays(vector<int>& weights, int days) {
//         low = max(a) and high = sum(a)
        low = 0;
        high = 0;
        for(auto w: weights){
            low = max(low, w);
            high += w;
        }
        
        int n = weights.size();
        // cout << low << " " << high << endl;
        
        while(low < high){
            mid = low + (high - low) / 2;
            curr = 0;
            d = 1;
            i = 0;
            while(curr <= mid && i < n){
                curr += weights[i];
                i++;
                if(curr > mid){
                    d++;
                    curr = 0;
                    i--;
                }
            }
            
            if(d <= days){
//                 number of days if we choose this are less than given days, so we need to increase the days, or reduce the bucket size
                high = mid;
            }else{
//                 number of days are more, so we need to increase the bucket size
                low = mid + 1;
            }
        }
        
        return low;
    }
};
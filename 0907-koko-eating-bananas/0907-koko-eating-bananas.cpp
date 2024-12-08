class Solution {
public:

    int findHours(vector<int>& v, int k){
        int res = 0;
        for(auto x: v){
            res += x / k;
            res += (x % k) ? 1 : 0; 
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid;

        while(low < high){
            mid = low + (high - low) / 2;
            int hours = findHours(piles, mid);
            if(hours > h){
                // koko gets caught
                // we MUST increase his speed
                low = mid + 1;
            }else{
                // hours <= h
                // koko can eat and stay idle
                // if equal, we are seeing to decrease the speed
                high = mid; 
            }
        }

        return low;
    }
};
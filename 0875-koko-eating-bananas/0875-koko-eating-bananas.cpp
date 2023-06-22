class Solution {
public:
    long long numberOfHours(vector<int>& piles, int k){
        // if my banana eating rate is k, then it would take how much amount of time to complete
        long long int time = 0;
        for(auto p: piles){
            time += (p % k == 0) ? (p / k) : 1 + (p / k);
        }
        return time;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid;
        int ans = INT_MAX;
        
        // finding the most optimal number using binary search
        while(low <= high){
            mid = low + (high - low) / 2;
            if(numberOfHours(piles, mid) > h){
                low = mid + 1;
            }else{
                // it is possible to eat under h hours
                // so we need to check even below
                ans = min(ans, mid);
                high = mid - 1;
            }
        }    
        
        return ans;
    }
};
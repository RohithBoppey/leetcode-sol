class Solution {
public:

    // for a certain time, find the number of cars that they can service in a GREEDY way

    unordered_map<long long, long long> dp;

    long long findCars(vector<int>& v, long time){

        if(dp[time] != 0){
            return dp[time];
        }

        long cars = 0;

        int n = v.size();
        int i = 0;

        for(int i = 0; i < n; i++){
            // for each mechanic, find out how many cars can he service
            long r = v[i];
            long c = 0;
            // r * c^2 so time = sqrt(time / rank)
            cars += sqrt(time / r);
        }

        return dp[time] = cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long ans = 0;

        long long mn = *min_element(ranks.begin(), ranks.end());
        int n = ranks.size();

        long long low = 1, high = mn * cars * cars, mid;

        while(low < high){
            mid = low + (high - low) / 2;

            // with the time as mid, find out how many number of cars can these mechanics repair
            long long c = findCars(ranks, mid);

            if(c < cars){  
                // servicing less cars
                // condititon failed, we must service all cars
                // so for that MUST increase time
                low = mid + 1;
            }else{
                // c >= cars
                // all cars are conditioned
                // but still time can be better
                // so take this and below
                high = mid;
            }

        } 

        return low;   
    }
};
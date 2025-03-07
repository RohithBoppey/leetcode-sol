class Solution {
public:
    bool isPrime(int n){
        if(n == 1){
            return false;
        }
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                // is divisible
                return false;
            }
        }

        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        int minDiff = INT_MAX;

        int a = 0, b = 0;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
            int sz = primes.size();
            if(sz >= 2){
                // find the last 2 diff
                int diff = primes[sz - 1] - primes[sz - 2];
                if(diff < minDiff){
                    // update the 2 variables
                    a = primes[sz - 2];
                    b = primes[sz - 1];

                    minDiff = diff;
                }
            }
        }

        if(primes.size() < 2){
            // cannot generate min
            return {-1, -1};
        }

        return {a, b};
    }
};
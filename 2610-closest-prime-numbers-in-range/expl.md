
Using a simple prime number check function: `Using SQRT approach`:
```c++
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
```

![WhatsApp Image 2025-03-07 at 20 39 34_6d557241](https://github.com/user-attachments/assets/ab92687f-91eb-46a1-8547-4b17d71688ea)
![WhatsApp Image 2025-03-07 at 20 39 51_7b042688](https://github.com/user-attachments/assets/18f02b34-a0d7-465d-96ba-08e27ea64e26)

2. Using *`Sieve of Eratosthenes`* Approach:    
Use this approach when primes are required in between [low, high] or some limits.


```c++
class Solution {
public:
    // using sieve of eratheneus approach
    vector<int> sieveHelper(int n){
        vector<int> primes(n + 1, 1);

        // initialising 0 and 1
        primes[0] = 0;
        primes[1] = 0;

        int val = 0;
        for(int i = 2; i <= sqrt(n); i++){
            // now use i to mark the multilpes as false
            val = 2 * i;
            while(val <= n){
                primes[val] = 0;
                val += i;
            }
        }

        return primes;

    }


    vector<int> closestPrimes(int left, int right) {
        vector<int> fprimes = sieveHelper(right);

        vector<int> primes;
        for(int i = left; i <= right; i++){
            if(fprimes[i]){
                primes.push_back(i);
            }
        }

        int minDiff = INT_MAX;
        int n = primes.size();

        if(n < 2){
            // no or 1 primes
            return {-1, -1};
        }

        // for(auto x: primes){
        //     cout << x << endl;
        // }

        int diff = INT_MAX, a = 0, b = 0;
        for(int i = 1; i < n; i++){
            diff = primes[i] - primes[i - 1];
            if(diff < minDiff){
                // update
                a = primes[i - 1];
                b = primes[i];

                minDiff = diff;
            }
        }

        return {a, b};

    }
};
```

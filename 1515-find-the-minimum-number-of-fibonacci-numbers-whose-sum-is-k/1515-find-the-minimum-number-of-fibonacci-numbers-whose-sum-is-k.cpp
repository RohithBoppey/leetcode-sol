class Solution {
public:
    void printV(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    int findMinFibonacciNumbers(int k) {
        // generate the fibonacci iteratively

        vector<int> fib;
        
        // base condition
        fib.push_back(1); // n = 1
        fib.push_back(1); // n = 2

        // generate until the last element is less than k
        int n = 2; // 2 elements in the array
        int last = 1;
        while(last <= k){
            int curr = fib[n - 1] + fib[n - 2];
            fib.push_back(curr);
            n++;
            last = curr;
        }

        // printV(fib);

        // the min number of coins would always be from the behind greedily
        // we know that solution definitely exists - SINCE IT IS FIBONACCI
        n = fib.size();
        int index = n - 1;

        int ans = 0;

        while(k != 0){
            while(k >= fib[index]){
                // remove the last element from the fibonacci continously
                k -= fib[index];
                ans++;
            }
            index--;
        }

        return ans;

    }
};
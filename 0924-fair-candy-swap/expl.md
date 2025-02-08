Simple bruteforce solution: Try swapping and all and check if the sum is equal
```c++
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        
        // required sum is the sum(1) + sum(2) / 2

        int s1 = 0, s2 = 0;
        for(auto &x: a){
            s1 += x;
        }

        for(auto &x: b){
            s2 += x;
        }

        // find required sum
        int rq = s1 + s2 / 2;

        // keep shuffling all and check if it is valid or not
        int n1 = a.size();
        int n2 = b.size();

        int ns1, ns2;

        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                // shift both of those
                ns1 = s1 - a[i] + b[j];
                ns2 = s2 - b[j] + a[i];

                cout << ns1 << " " << ns2 << endl;
                // these 2 should be equal to the required_sum
                if(ns1 == ns2){
                    // meaning we can shift this pair
                    vector<int> ans;
                    ans.push_back(a[i]);
                    ans.push_back(b[j]);
                    return ans;
                }
            }
        }

        return {};
    }
};
```

But the key in here is to use the **Binary Search!**
```c++
class Solution {
public:

    bool isPresent(vector<int>& v, int value){

        int n = v.size();

        int low = 0, high = n - 1, mid;

        while(low <= high){
            mid = low + (high - low) / 2;

            if(v[mid] > value){
                // move to the left
                high = mid - 1;
            }

            else if (v[mid] < value){
                low = mid + 1;
            }
            else{
                return true;
            }
        }

        return false;

    }

    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        
        // required sum is the sum(1) + sum(2) / 2

        int s1 = 0, s2 = 0;
        for(auto &x: a){
            s1 += x;
        }

        for(auto &x: b){
            s2 += x;
        }

        // sort the arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());


        // simple formula
        // b[j] = s2 - s1 + 2a[i] / 2 -> check if such value exists in b for a certain a[i]
        for(int i = 0; i < a.size(); i++){
            int rq = (s2 - s1 + 2 * (a[i])) / 2;

            // see if such value exists in b -> then return that value
            if(isPresent(b, rq)){
                return {a[i], rq};
            }
        }

        return {};
        
    }
};
```



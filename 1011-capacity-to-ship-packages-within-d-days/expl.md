Interesting problem with Binary Search algorithm: 
![image](https://github.com/user-attachments/assets/5b396da1-410e-4d30-81a6-9eec084e27b8)
![image](https://github.com/user-attachments/assets/63ae63c2-fe59-4a5a-960d-d2cec15ad073)

```c++
class Solution {
public:
    int reqDays(vector<int>& w, int cap){
        int curr = 0, rq = 1;
        for(auto x: w){
            curr += x;
            if(curr > cap){
                rq++;
                curr = x;
            }
        }
        return rq;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = 0, high = 0;
        
        for(auto x: weights){
            low = max(x, low);
            high += x;
        }

        // find the optimal number of weight while keeping days concrete
        // it is okay if we get the num_days < days - true condition, but should not get > days - false condition

        // mid is the capacity of the ship
        int mid;
        while(low < high){
            mid = low + (high - low) / 2;
            int rd = reqDays(weights, mid);

            if(rd <= days){
                // still we can ship is more days, but we are seeing to further reduce it down
                // can possible but can still trim
                high = mid;
            }else{
                low = mid + 1;
            }

        }

        return low;
    }
};
```​

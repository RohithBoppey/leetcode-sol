Slightly tricky because of the infinite loop condition: 
![WhatsApp Image 2025-03-17 at 22 55 37_dda48df8](https://github.com/user-attachments/assets/62b2ca4b-bca8-414a-8f1a-607415f7bbd8)

So to prevent to not point to the same condition always, we are changing low to `low <= high` and making `low = mid + 1`, when not needed. We push the mid out of the infinite loop and the `high` can take care of it.

```c++
class Solution {
public:

    // this function returns the number of children that 
    long long children(vector<int>& v, long long k){
        long long ans = 0;
        
        for(auto x: v){
            // for each element, find the number of piles we can create
            ans += (long long)x / k;
        }

        return ans;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        

        long long low = 1, high = 10000001, mid;

        // cout << children(candies, 3) << endl;
        // cout << children(candies, 5) << endl;


        while(low <= high){
            // cout << low << " " <<  mid  << " " << high << endl;

            mid = low + (high - low) / 2;

            // find the number of children we can serve with the current pile size
            long long c = children(candies, mid);

            if(c >= k){
                // all the children are served, but can increase the pile size for better profit
                // but can also include so that it can act as answer
                low = mid + 1;
            }else{
                // c < k
                // all children are not being served
                // MUST decrease the pile size
                high = mid - 1;
            }
        } 

        return high;

    }
};
```

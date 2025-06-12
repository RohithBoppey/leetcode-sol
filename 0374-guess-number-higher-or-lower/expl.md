
Very similar to finding index in binary search

```c++
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        // we do not know the exact number
        int low = 1, high = n, mid;
        int res, ans; 

        while(low <= high){
            mid = low + (high - low) / 2;
            res = guess(mid);

            // iterate based on the search space
            if(res == 0){
                // matched
                return mid;
            }

            else if(res == -1){
                // picked higher number
                // reduce search range
                high = mid - 1;
            }

            else{
                // 1 -> we picked a lower number
                // increase search range
                low = mid + 1;
            }
        }

        return n;
    }
};
```

```c++
nums =   [7,2,5,10,8], k = 3
prefix = [7,9,14,24,32]

- we must divide into 3 sub arrays (MUST)
possibilities: 

breaking point after 7:
7 2 5,10,8 - 23
7 2,5 10,8 - 18
7 2,5,10 8 - 19

breaking point after 2:
7,2 5 10,8 - 18
7,2 5,10 8 - 15

breaking point after 5:
7,2,5 10 8 - 14

14 IS THE ANSWER

1.
i=0 -> standing at 7
range => low = 2, high = 24 - the max sum lies here
mid = 13
how many divisions/subarrays that we have to make here such that the max sum is 13 ->
(how to check???) -> 
[7,2,5,10,8] 
7,2 | 5 | 10 | 8 -> (divisions > k) -> requiring 4 divisions, but the limit given as 3 -> so MUST increase the max sum
-> low = mid + 1

2. 
low = 14, high = 24 
mid = 17
how many divisions should we make such that max subarray sum is 17 
[7,2,5,10,8]
7,2,5 | 10 | 8 -> found <= k divisions, now can further decrease the sum further to check whether how many divisions should we need
-> high = mid

3.
low = 14, high = 17
mid = 15
how many divisions should we make so that max sum of a subarray is 16 -> just calculate divisions 
[7,2,5,10,8]
7,2,5 | 10 | 8 -> div <= k -> can select, but also still can decrease the sum
-> high = mid

4.
low = 14, high = 15
mid = 14
how many divisions? [7,2,5,10,8] => 7,2,5 | 10 | 8 -> 3 -> can decrease the sum 

*NARROWED DOWN TO 14*
```

```c++
class Solution {
public:

    int n;
    int solve(vector<int>& v, int sum){
        int divs = 1;
        long curr = 0;

        for(int i = 0; i <n; i++){
            curr += v[i];
            if(curr > sum){
                // should break the array
                divs++;
                curr = v[i];
            }
        }

        return divs;
    }

    int splitArray(vector<int>& nums, int k) {
        
        n = nums.size();

        // we are selecting the range for the max sum that can be obtained from a subarray
        // so min is max(arr) because we are breaking all the elements as single and max of sums would be max(arr), max is sum(arr)

        int low = INT_MIN, high = 0;
        for(auto &x: nums){
            low = max(low, x);
            high += x;
        }

        int mid;
        while(low < high){
            mid = low + (high - low) / 2;

            // max number of divisions that can be obtained if the max sum is mid
            int divs = solve(nums, mid);

            if(divs > k){
                // we must definitely increase the max sum that is obtained, so that number of divs are reduced, even this sum is unacceptable
                low = mid + 1;
            }
            else{
                // k is getting satisfied, but still the sum can be reduced (as per the question), but this is also satisfied
                high = mid;
            }

        }

        return low;
    }
};
```

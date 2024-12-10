Explanation: 
```c++
arr = [1,2,5,9] t= 6
choose the minimum divisor, when divided with the arr[i] and sum, should give sum <= threshold

min divisor = 1 -> sum = 16
max divisor = 10 -> sum = 0

range = 1, 10

1. 
low = 1, high = 10
mid = 5
when divisor = 5 -> sum = 1,1,1,2 = 5 <= threshold ===> can *select* this as divisor and also can decrease the divisor so that the sum can increase
-> high = mid

2.
low = 1, high = 5
mid = 3
when divisor = 3 -> sum = 1,1,2,3 = 7 >= threshold ===> failing the condition, we must definitely reduce the sum -> increase the divisor and not include 3
-> low = mid + 1

3.
low = 4, high = 5 -> it narrows down to 5

-----------------

arr = [44,22,33,11,1] t = 5

min divisor = 1, 
max = 45

range = 1,45

1.
low = 1, high = 45
mid = 23
sum => 2,1,1,1,1 = 6 > t -> *must* decrease sum -> increase divisor
-> low = mid + 1

2. 
low = 24, high = 45
mid = 34
sum = 2,1,1,1,1 > t
-> low = mid + 1

3. 
low = 35, high = 45 -> narrows to 45
```

```c++
class Solution {
public:

    int giveSum(vector<int>& v, int d){
        int sum = 0, r;
        for(auto &x : v){
            sum += x / d;
            r = x % d;
            sum += (r) ? 1 : 0;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();

        int low = 1, high = 1000001;
        int mid;
        while(low < high){
            mid = low + (high - low) / 2;
            int sum = giveSum(nums, mid);

            if(sum <= t){
                // this divisor is acceptable, but the sum can be increased -> divisor can be decreased
                high = mid;
            }else{
                // sum > t
                // *not acceptable* -> must reduce the sum -> increase the divisor
                low = mid + 1;
            }
        }

        return high;

    }
};
```

# Better understanding: 


The idea is simple, the only tricky case in here is handling 0: 
- if there is one zero, only that gets the whole product of the array, all the other elements gets 0
- if zeroCount > 1, then all are 0
- else, divide the array elements from the count  

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int z = 0;
        vector<int> sol(n, 1);

        long long int v = 1;
        // calculcate the product beforehard
        for(auto x: nums){
            z += (x == 0) ? 1 : 0;
            v *= (x == 0) ? 1 : x;
        }

        // fill based on the values 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                sol[i] = (z > 1) ? 0: (int) v;
            }else{
                sol[i] = (z != 0) ? 0 : (int) (v / nums[i]);
            }
        }

        return sol;
    }
};
```

## Optimized approach: 
[Solution](https://leetcode.com/problems/product-of-array-except-self/solutions/1342916/3-minute-read-mimicking-an-interview)

Using the concept of prefix sum: 
- at any i, consider the prefix sum to be the product found until the before element except the self element
- like in this case [1, 2(x), 3, 4], the prefix product would be all the elements before 2. so prefix[i - 1] * nums[i - 1]
- similarly suffix product, hence:
- at a certain x, the actual desired product can be pre[i] * suff[i]

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Using prefix sum approach

        int n = nums.size();
        vector<int> pre(n, 1), suff(n, 1);

        // base
        pre[0] = 1;
        suff[n - 1] = 1;

        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            suff[i] = suff[i + 1] * nums[i + 1];
        }

        // its just pre[i] * suff[i] --- for a certain nums[i]
        for(int i = 0; i < n; i++){
            nums[i] = pre[i] * suff[i];
        }

        return nums;

    }
};
```

## Final optimized approach:
![WhatsApp Image 2025-05-27 at 09 44 08_c5a5624d](https://github.com/user-attachments/assets/25a249ae-86cb-4126-829d-33c6fef9a296)

```c++
class Solution {
public:
    int n;

    vector<int> productExceptSelf(vector<int>& nums) {
        // final optimized solution

        n = nums.size();

        //  calculate prefix and suffix on the go
        vector<int> ans(n, 1);

        int curr;
        // prefix
        curr = 1;
        // left sum
        for(int i = 0; i < n; i++){
            // update the current value with the prefix calculated so far
            ans[i] *= curr;
            // update current so it includes the current value --> need it for the next step
            curr *= nums[i];
        }

        // right sum
        curr = 1;
        for(int i = n - 1; i >= 0; i--){
            // take in the current value with suffix 
            ans[i] *= curr;
            curr *= nums[i];
        }

        return ans;

    }
};
```

-------------------------------

CRAPPY SOLUTION:    
```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, np = 1, allZero = 1, nz = 0;
        int n = nums.size();
        for(auto x: nums){
            product *= x;
            if(x != 0){
                np *= x;
                allZero = 0;
            }else{
                nz++;
            }
        }
        
        if(allZero == 1){
            // all are zeroes
            return vector<int>(n, 0);
        }
        
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(nz == 1){
                    // only this is the zero
                    res[i] = np;
                }else{
                    res[i] = 0;
                }
            }else{
                res[i] = product / nums[i];
            }
        }
        return res;
    }
};
```
+ If all are non-zero, simple product & then divide by the current element => product/nums[i]
+ But if there is a zero: count number of zeroes and proceed.

------------------------


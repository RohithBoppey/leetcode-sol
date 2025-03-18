## Slightly Unoptimised solution
![WhatsApp Image 2025-03-18 at 10 45 38_c693bd2f](https://github.com/user-attachments/assets/f27a00de-98b7-41b6-94e3-191f1ca15274)
![image](https://github.com/user-attachments/assets/609bbda9-94d7-46a1-8563-952b1d9c47c1)

First concept is finding if the subarray is nice or not in O(N) - **running window**!   
Slightly unoptimised solution using the logic from above, in the first for loop, we are finding the max length of nice subarray starting from position i:    
```c++
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // using O(n²) solution

        int n = nums.size();
        int i = 0, j = 0;

        int running, ans = 0;

        // this for loop is to find the max length of the nice subarray starting from this position
        for(int i = 0; i < n; i++){
            // reset running for the next loop
            running = 0;
            for(int j = i; j < n; j++){
                if((running & nums[j]) != 0){
                    // i to j subarray is not nice
                    // no point in moving j
                    break;
                }

                // i to j subarray is nice
                // can proceed further
                running = (running | nums[j]);
                ans = max(ans, j - i + 1);

            }
        }  

        return ans; 
    }

};
```
----

## Sliding Window solution
Slightly tricky one -   
![image](https://github.com/user-attachments/assets/b0d3ecea-63c2-4f85-9b98-c3941c8e4955)  
  
```c++
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // sliding window approach

        int n = nums.size();
        int i = 0, j = 0, running, ans = 0;

        running = 0;
        while(j < n){
            // shrink until you find the valid one
            while((nums[j] & running) != 0){
                // xor undoes the change from the right
                running = (running ^ nums[i]);
                i++;
            }

            // standing at single element as the worst case, which is valid
            // or a subarray which is valid
            ans = max(ans, j - i + 1);
            running = (running | nums[j]);
            j++;
        }

        return ans;
    }
};
```

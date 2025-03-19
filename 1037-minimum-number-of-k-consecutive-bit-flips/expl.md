
When the num is 0, then do a flip in the next subarray -> 
![image](https://github.com/user-attachments/assets/8ba53953-f57a-4804-89b5-aa50f0f8ce8f)

But when the num is 1, and then odd number of flips on it head, then you have to flip it again -^
![image](https://github.com/user-attachments/assets/102f4e61-6660-4ceb-8a47-d2c472389935)

Using Same logic but TLE! 110/113 ❌
```c++
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();

        // add another array for the count of flips for each
        vector<int> flips(n, 0);
        int tf = 0; //total flips

        int i = 0;
        while(i < n){
            // check and do the flip
            if(
                (nums[i] == 0 && flips[i] % 2 == 1) 
                || 
                (nums[i] == 1 && flips[i] % 2 == 0)
            ){
                // no need of flipping
                i++;
            }else{
                // we need to flip the k-size window
                int t = k, j = i;

                // boundary condition
                if(i > n - k){
                    // cannot proceed further
                    return -1;
                }

                tf++;
                while(t != 0){
                    flips[j]++;
                    j++;
                    t--;
                }
                i++;
            }
        }

        return tf;

    }
};
```

### Needs optimisation for the the flips[], can we use a variable for it instead? 

![WhatsApp Image 2025-03-19 at 23 05 19_c186336e](https://github.com/user-attachments/assets/709e373e-cc09-43d6-b373-5a2f36d2e065)

```c++
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();

        // using number instead of array
        int flipCount = 0;
        vector<int> flips(n, 0);
        
        int tf = 0; //total flips

        int i = 0;
        while(i < n){
            // check the influence and adjust the flipCount for the certain i
            if(i >= k){
                // subarray found
                if(flips[i - k] == 1){
                    // now at this point, influence has vanished, and we are having one extra 
                    // so reduce 1
                    flipCount--;
                }
            }


            // check and do the flip
            if(
                (nums[i] == 0 && flipCount % 2 == 1) 
                || 
                (nums[i] == 1 && flipCount % 2 == 0)
            ){
                // no need of flipping
                i++;
            }else{
                // boundary condition
                if(i > n - k){
                    // cannot flip
                    return -1;
                }

                // we need to flip the k-size window
                tf++;
                flipCount++;

                // mark in flips
                flips[i] = 1;

                i++;
            }
        }

        return tf;

    }
};
```

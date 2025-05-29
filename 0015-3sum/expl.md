optimal approach:           

![WhatsApp Image 2023-07-13 at 15 28 46](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/9a90af02-5385-44b4-b478-4407cbd60ced)

this approach includes fixing one pointer in a loop (i) but ensure that it is not repeating, same with low and high     
when low + high + i index result in 0, we have found our pair       
after that, move low and high accordingly which is not repeating

![WhatsApp Image 2023-07-05 at 16 41 26](https://user-images.githubusercontent.com/73538974/251131823-568f9ae4-0f5c-45e4-bb68-64beeaaf851e.jpg)
            
![WhatsApp Image 2023-07-05 at 16 41 27](https://user-images.githubusercontent.com/73538974/251131862-64c20ccc-f4a9-4982-b613-e5b90388c896.jpg)

![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/1fc54c77-c489-4f27-8a3c-c81b353fe738)                        


OPTIMAL CODE:
```c++
class Solution {
public:

    vector<vector<int>> res;

    // generic way
    void solve(vector<int>& nums, int target){
        int n = nums.size(); 

        int low, high;
        int sum = target; 

        vector<int> ans(3, 0);
        sort(nums.begin(), nums.end());
        
        // need 3 elements, so iterating only until n - 2
        for(int i = 0; i < n - 2; i++){ 

            // to remove duplicate processing
            if(i != 0 && nums[i] == nums[i - 1]){
                continue;
            }

            sum = 0;
            // starting from immediate pos
            low = i + 1;
            high = n - 1;

            // keep finding the sum by adjusting low and high accordingly
            while(low < high){ // not coincide coz we need 3 ele   
                // check the sum now

                sum = nums[low] + nums[high] + nums[i];

                if(sum == target){
                    // put in ans
                    ans = {nums[i], nums[low], nums[high]};
                    res.push_back(ans);

                    // move to the next low and high to prevent duplicates
                    while(low < high && nums[low] == nums[low + 1]) low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;

                    // now it is pointing to the repeated value last occurance
                    low++;
                    high--;

                }else{
                    // adjust low and high
                    if(sum < target){
                        // sum is left, can increase low
                        low++;
                    }else{
                        // sum is negative, should decrease high
                        high--;
                    }
                }


            }

        }

    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size(); 
        int target_sum = 0; /// can change whenever needed
        solve(nums, target_sum);
        return res;
    }
};
```

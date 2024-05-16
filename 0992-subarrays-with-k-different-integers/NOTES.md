​MY INTUITION: 
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/7ceb5911-98fa-4f8a-a052-dfb341244e1a)
      
THE MAIN PROBLEM THAT WE FACE HERE IS THAT => WE CAN FIND THE NUMBER OF SUBARRAYS ENDING AT INDEX J AS => `j - i + 1`, BUT HERE WE NEED TO ALSO MAKE SURE THAT THE SUBARRAYS ARE VALID.      
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/1417c615-5486-4647-b9db-8457ed369543)    
HERE I CAN FIND SUBARRAYS ENDING AT J AS: [1,2,1] [2,1] [1] => **BUT WE NEED TO DISCARD [1] AS BEING VALID**. HOW????        
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/b0836a60-cb40-46a1-8ac2-0b2d547d59b7)      
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/e9290ca8-c01d-49a0-a175-2a65f4935ca0)    
      
ALGORITHM:      
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/048c37e9-d1e5-4c6a-82b1-d3bb6f5fba27)
      
```
class Solution {
public:
    
    int slidingWindow(vector<int>& nums, int k){
        // even if k == 1 there could be case like [1,2,1,1,1,1,3]
        
        // we are returning number of subarrays with dis <= k
        unordered_map<int,int> mp; // to store freq
        int n = nums.size();
        int i = 0, j = 0;
        
        int ans = 0;
        
        while(j < n){
            mp[nums[j]]++;
            
            // we need to always have dis <= k
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            // means valid -- dis <= k
            // adding number of subarrays that end at index j
            ans += j - i + 1;
            j++;
        }
        
        // cout << ans << endl;
        return ans;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // <=3 - <=2 ----- === 3
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
```

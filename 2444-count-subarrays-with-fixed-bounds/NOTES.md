## NOT A SLIDING WINDOW APPRAOCH

![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/516bf4e2-0a10-46c4-b188-c848b00fe73b)      
      
WE CAN GO LEFT UNTIL WE FIND A CULPRIT index --- it is either < mn or > ms & also while going, we need to make sure that -- one mn & one ms is present in the subarray, once that condition is satisfied --- we can go left until we find a culprit index    
      
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/ae341620-8b73-4b32-9bae-376ba7a4068d)      
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/3c623a1b-5a0b-43fa-a393-1eef8a4e9a58)
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/6c4c1b9f-59a4-47ac-a486-87168629d040)
      
```
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mn, int ms) {
        int n = nums.size();
        int i = 0, mni = -1, msi = -1, id, clid = -1, t;
        long long ans = 0;
        
        /*
        in each iteration,
        + we update min idx, max idx --- we take min out of those and from that index, we can go left until we find the culprit idx
        + then we can add (id - clid) -- to give the number of subarrays for the ans     
        */
        
        for(int i = 0; i < n; i++){
            
            // updating msi, mni
            if(nums[i] == mn){
                mni = i;
            }
            if(nums[i] == ms){
                msi = i;
            }
            
            if(nums[i] < mn || nums[i] > ms){
                // culprit idx found
                clid = i;
            }
            
            // from that index, we go left until clid is found and can be added directly
            id = min(msi, mni);
            t = id - clid;
            ans += (t >= 0) ? t : 0;
        }
        
        
        return ans;
    }
};
```​

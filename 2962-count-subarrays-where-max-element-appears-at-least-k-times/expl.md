​MY INTUITION:   
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/6a98333d-0f06-445b-86aa-d2509b5a1ae5)    
        
THOUGH IDEA IS SOMEHOW CORRECT, WE CAN OBSERVE TLE:   624/633 ✅      
```
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        // first step is to find the max element
        // all positives
        int ms = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            ms = max(ms, nums[i]);
        }
        // cout << ms << endl;
        // now ms denotes the max element
        long long count = 0;
        int f = 0;
        int i = 0, j = 0;
        
        while(j < n){
            if(nums[j] == ms){
                f++;
            }
            // cout << f << endl;
            if(f >= k){
                // we need to remove from behind
                // count++;
                i = 0;
                int t = f;
                while(i <= j && t >= k){
                    if(nums[i] == ms){
                        // removed from behind
                        t--;                        
                    }
                    count++;
                    i++;
                }
            }
            j++;
        }
        
        return count;
    }
};
```
THIS IS NOT THE SAME ONE AS: [SUBARRAY PRODUCT < K](https://leetcode.com/problems/subarray-product-less-than-k/). THERE IT WORKS BECAUSE IF PRODUCT IS LESS, ALL ARE VALID - CAN INCLUDE. BUT HERE OPPOSITE, NOT FROM BACK, FRONT IS NEEDED    
      
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/8db1a8bf-b936-4c54-baec-496fdb42a314)      
      
```
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        // first step is to find the max element
        // all positives
        int ms = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            ms = max(ms, nums[i]);
        }
        // cout << ms << endl;
        // now ms denotes the max element
        long long count = 0;
        int f = 0;
        int i = 0, j = 0;
        
        while(j < n){
            if(nums[j] == ms){
                f++;
            }
            // cout << f << endl;
            
            while(f >= k){
                // the current subarray configuration will be included in all the subarrays to the right
                count += n - j;
                
                // keep doing while removing i
                if(nums[i] == ms){
                    f--;
                }
                i++;
            }
                        
            j++;
        }
        
        return count;
    }
};
```




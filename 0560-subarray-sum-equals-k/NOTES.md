using prefix sum and hashmap concept, since there are negatives, it is not possible to use sliding window       
![image](https://user-images.githubusercontent.com/73538974/251375072-85ff4990-6bcb-408f-b2db-33a85e90b63b.png)

![WhatsApp Image 2023-07-06 at 13 10 06](https://user-images.githubusercontent.com/73538974/251379570-5d6d546e-e92b-4268-8525-c40757d21361.jpg)
![WhatsApp Image 2023-07-06 at 13 10 07](https://user-images.githubusercontent.com/73538974/251379929-5f2403c8-d5d5-4d96-bbc8-b6fd364adcc5.jpg)

for [Largest Subarray Length with sum K](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1), there is a slight modification, we are making the hashmap  <prefixSum, index> and whenever we are getting the sum, we are getting the sum equal to current target, that is the longest subarray      

![(76) Largest Subarray with Zero Sum  Amazon  MMT 00-09-51](https://user-images.githubusercontent.com/73538974/251382519-23da7207-4599-4466-9790-68205f1ade8e.png)

GENERAL FUNCTION: 
```
/*You are required to complete this function*/

class Solution{
    public:
    
    int solve(vector<int>& v, int target, int n){
        int mx = 0;
        // this map contains mapping <prefixSum, initialIndex>
        unordered_map<int, int> mp;
        
        int curr = 0, cl;
        
        for(int i = 0; i < n; i++){
            curr += v[i];
            if(curr == target){
                // that is the maximum
                mx = i + 1;
            }else{
                // find if remaining exists
                if(mp.find(curr - target) != mp.end()){
                    // it exists
                    cl = i - mp[curr - target];
                    mx = max(cl, mx);
                }else{
                    mp[curr] = i;
                }
            }
        }
        
        return mx;
    }
    
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        return solve(A, 0, n);
    }
};
```

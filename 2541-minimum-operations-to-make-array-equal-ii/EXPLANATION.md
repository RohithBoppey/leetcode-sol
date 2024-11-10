
Simple solution - while the 2 entries are not equal, find the i and j position in brute force way, and do the operation - TLE ❌
```c++
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        
        int n = nums1.size();
        
        for(int start = 0; start < n; start++){
            while(nums1[start] != nums2[start]){
                // keep choosing i and j to solve this
                int i = start, j = start;
                
                // keep finding i
                while(i < n){
                    if(nums1[i] < nums2[i] && (nums2[i] - nums1[i]) % k == 0){
                        // is divisible and can add to it
                        break;
                    } 
                    i++;
                }
                
                // keep finding j
                while(j < n){
                    if(nums1[j] > nums2[j] && (nums1[j] - nums2[j]) % k == 0){
                        // is divisible and can add to it
                        break;
                    } 
                    j++;
                }
                 
                if(i >= n || j >= n){
                    return -1;
                }
                
                // do the operation
                nums1[i] += k;
                nums1[j] -= k;
                ans++;
            }
        }
        
        return ans;
    }
};
```
Instead, we can go with a simple approach, we can either do addition for any step or else difference right? Just calculate them seperately, instead of finding out the exact pairs, that should do the trick. After calculating the sum and diff, check whether they are the same or not - they should be the same because, they are being done in the same step.

This combined with other checks, isSame, k = 0, should be the final solution

```c++
class Solution {
public:
    
    int isEqual(vector<int>& v1, vector<int>& v2){
        int n = v1.size();
        
        for(int i = 0; i < n; i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        
        return true;
    }
    
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {        
        int n = nums1.size();
        
        long long sum = 0, diff = 0;
        
        if(isEqual(nums1, nums2)){
            return 0;
        }
        
        if(k == 0) return -1;
        
        for(int i = 0; i < n; i++){
            if(nums1[i] > nums2[i]){
                if(
                    (nums1[i] - nums2[i]) % k == 0
                ){
                    diff += (nums1[i] - nums2[i]) / k;
                }else{
                    return -1;
                }
            }
            else if(nums1[i] < nums2[i]){
                if(
                    (nums2[i] - nums1[i]) % k == 0
                ){
                    sum += (nums2[i] - nums1[i]) / k;
                }else{
                    return -1;
                }
            }
        }
        
        return (sum == diff) ? sum : -1;
    }
};
```


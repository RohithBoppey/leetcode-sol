​way too complex 2 pointer solution:

```
int findMaxConsecutiveOnes(vector<int>& nums) {
        // using the concept of sliding window
        
        int n = nums.size();
        
        int i = 0, j = 0;
        
        int ans = 0;
        
        while(j < n){
            
            if(nums[j] == 1){
                j++;
            }
            else {
                
                // it is not 1
                // find max size of 1s and compare
                ans = max(ans, j - i);
                
                // find the next 1
                while(j < n && nums[j] != 1) {j++;}
                i = j;    
            }
        }
        
        if(i != n){
            // last set of 1 are still there
            ans = max(ans, j - i);
        }
        
        return ans;
        
    }
```

simple solution using a single count

```
int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                mx = max(count, mx);
            }else{
                count = 0;
            }
        }
        return mx;
    }
```

// we need to find the length of longest consecutive elements sequence            
// we cannot sort -> O(n2) complexity                  
​                    
// need to be in O(n) time                  

![WhatsApp Image 2023-07-06 at 11 34 27](https://user-images.githubusercontent.com/73538974/251359031-b56c7226-9426-41ab-85b9-eeb71b53846b.jpg)
            
for the better working solution, we can use this:       
```
int longestConsecutive(vector<int>& nums) {
      // this is not optimal approach, just better approach
      int n = nums.size();

      if(n == 0){
          return 0;
      }

      // sorting to find the sequence
      sort(nums.begin(), nums.end());

      int count = 1, last_ele = nums[0], maxCount = 1;

      for(int i = 1; i < n; i++){
          if(nums[i] == last_ele + 1){
              // it is in a sequence
              count++;
              last_ele = nums[i];
          }else if(nums[i] == last_ele){
              // do nothing
          }else{
              // reset the counter
              count = 1;
              last_ele = nums[i];
          }
          maxCount = max(maxCount, count);
      }
      return maxCount;
  }
```
but is not optimal because we are sorting.      

the idea is like sort it and find the sequence by traversing      


OPTIMAL: something like **moores algorithm**, where are trying to find the sequence, instead we are having count and finding it        
this is just better not optimal cause it includes sorting       







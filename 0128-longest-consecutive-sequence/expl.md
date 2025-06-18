// we need to find the length of longest consecutive elements sequence            
// we cannot sort -> O(n2) complexity                  
​                    
// need to be in O(n) time                  

![WhatsApp Image 2023-07-06 at 11 34 27](https://user-images.githubusercontent.com/73538974/251359031-b56c7226-9426-41ab-85b9-eeb71b53846b.jpg)

- one basic approach is using an ordered_map just to find the order of elements: like 1,2,3,4 as keys and check if that key exists or not

```c++
class Solution {
public:
    int n;
    map<int, int> mp;

    int longestConsecutive(vector<int>& nums) {
        n = nums.size(); 
        int ans = 0;
        for(auto &x: nums){
            mp[x]++;
        }    

        int start = INT_MIN, next = INT_MIN;
        int val;
        for(auto &it: mp){
            // cout << it.first << endl;
            val = it.first;
            if(start == INT_MIN || next == INT_MIN){
                // started just now, base condition
                start = val;
                next = val + 1;
                ans = 1; // since default is one
            }else{ 
                if(val == next){
                    // next element found
                    ans = max(ans, next - start + 1);
                    next++;
                }else{
                    start = val;
                    next = val + 1;
                }
            }
        }

        return ans;
    }
};
```

- but for optimal solution, we will have to use set as the insertion and lookup is nearly O(1)
- TLE solution because we are not considering if it is the start of the sequence or not
```c++
class Solution {
public:
    int n;
    set<int> st;

    int longestConsecutive(vector<int>& nums) {
        n = nums.size(); 
        int start = -1, end = -1, val;
        
        for(auto &x: nums){
            // for each element check in the set, first insert
            st.insert(x);
        }

        int ans = 0;

        for(auto &x: nums){
            // find how much can we reach further
            start = x;
            end = x;
            while(st.find(end) != st.end()){
                end++;
            }
            ans = max(ans, end - start);
        }
        
        return ans;
    }
};
```
- Working solution without TLE, etc.
```c++
class Solution {
public:
    int n;
    set<int> st;

    int longestConsecutive(vector<int>& nums) {
        n = nums.size(); 
        int start = -1, end = -1, val;
        
        for(auto &x: nums){
            // for each element check in the set, first insert
            st.insert(x);
        }

        int ans = 0;

        for(auto &x: st){
            // if not start of the sequence, continue
            if(st.find(x - 1) != st.end()){
                continue;
            }
            
            // find how much can we reach further
            start = x;
            end = x;
            while(st.find(end) != st.end()){
                end++;
            }
            ans = max(ans, end - start);
        }
        
        return ans;
    }
};
```
            
for the better working solution, we can use this:       
```c++
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







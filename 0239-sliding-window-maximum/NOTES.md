PRIORITY QUEUE DRY RUN ON : [1,3,-1,-3,5,3,6,7,3,-1,-3,5]
               
![image](https://user-images.githubusercontent.com/73538974/260930948-9aa75e3f-f6d3-4663-984b-72a8bf08ca9d.png)
![image](https://user-images.githubusercontent.com/73538974/260930986-02ddb2b5-a9e3-4ba2-95fb-ec0bb27dc0ae.png)
![image](https://user-images.githubusercontent.com/73538974/260931015-7c4fd7d0-5b65-44e8-8340-31ce1932dca4.png)
![image](https://user-images.githubusercontent.com/73538974/260931043-e7cc5ac2-d622-4303-bb83-c0432ab207aa.png)
![image](https://user-images.githubusercontent.com/73538974/260931067-730ec005-8a42-4355-91d4-973d880bcf76.png)
![image](https://user-images.githubusercontent.com/73538974/260931109-d92a8853-79a6-4b42-8151-8bb025b0bbb7.png)
                  
PRIORITY QUEUE CODE:
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        
        // always checking the new index
        // first k-1 elements require nothing to be done
        // using priority queue
        
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < k - 1; i++){
            pq.push({nums[i], i});
        }
        
        // for [k-1,n-1] elements, the max should be pushed into result
        
        // after pushing check for the valid index, else remove it
        // i.e. top index has to be present in i - (k - 1) index only
        
        int t;
        for(int i = k - 1; i < n; i++){
            pq.push({nums[i], i});
            while(!pq.empty() && pq.top().second < i - k + 1){
                pq.pop();
            }
            t = pq.top().first;
            result.push_back(t);
        }
        
        return result;
    }
};
```

USING DEQUE CONCEPT AND OVERLAPPING (4 STEPS): 
DRY RUN ON [1,3,-1,-3,5,3,6,7,3,-1,-3,5]: 
                  
![image](https://user-images.githubusercontent.com/73538974/260969455-0cb81f54-8c8e-4d94-89b7-f174523b8d63.png)
![image](https://user-images.githubusercontent.com/73538974/260969501-26bd8494-ff75-479f-9916-30f3cce1aae2.png)
![image](https://user-images.githubusercontent.com/73538974/260969535-d9b5fd7c-7976-4399-8d22-459551c9a1c6.png)
![image](https://user-images.githubusercontent.com/73538974/260969580-c6047835-20a0-4f5c-aaee-11cc12c8eda3.png)
![image](https://user-images.githubusercontent.com/73538974/260969626-631b95db-348d-4b3b-b622-6bb915cd7653.png)
![image](https://user-images.githubusercontent.com/73538974/260969655-c0ae20bd-3923-4266-ad45-7031ec884ed5.png)
![image](https://user-images.githubusercontent.com/73538974/260969693-16d7fbca-6177-46ef-85e4-7b5689376aef.png)
![image](https://user-images.githubusercontent.com/73538974/260969733-41a7eb6a-6b54-4d37-92c8-3f67fd4f0977.png)

                  
CODE:
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> result;
        int n = nums.size();
        
        // using deque to store index
        
        deque<int> dq; // to store index
        
        for(int i = 0; i < n; i++){
            
            // make space for new element by removing which are not in the range of index 
            while(!dq.empty() && dq.front() < i - (k - 1)){
                dq.pop_front();
            }
            
            // if the current index is more, overlap the rest
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                // since overlapping
                dq.pop_back();
            }
            
            // push now
            dq.push_back(i);
            
            // if the window constaint matches, start pushing into answer
            if(i >= k - 1){
                result.push_back(nums[dq.front()]);
            }
            
        }
        
        return result;
    }
};
```

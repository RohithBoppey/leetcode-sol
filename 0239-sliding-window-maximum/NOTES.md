
DRY RUN ON : [1,3,-1,-3,5,3,6,7,3,-1,-3,5]

      
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

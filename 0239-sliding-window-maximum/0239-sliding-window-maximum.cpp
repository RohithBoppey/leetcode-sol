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
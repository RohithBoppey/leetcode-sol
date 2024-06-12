class Solution {
public:
    
    priority_queue<pair<int,int>> pq;
    int n;
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // using priority queue solution
        n = nums.size();
        int i = 0, j = 0;
        int c, v;
        vector<int> ans;
        while(j < n){
            c = nums[j];
            pq.push({c, j});
            // the current index -> top should be in the range [j, j - k + 1]
            if(j - i + 1 < k){
                // nothing to do
            }else{
                while(!pq.empty() && pq.top().second < j - k + 1){
                    pq.pop();
                }
                v = pq.top().first;
                ans.push_back(v);
                i++;
           }
            j++;
        }
        return ans;
    }
};
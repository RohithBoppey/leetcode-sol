class Solution {
public:
    priority_queue<pair<int,int>> pq;
    vector<int> ans; 
    int n;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        n = nums.size(); 
        int i = 0, j = 0;

        while(j < n){
            // no matter what, push in the queueu
            pq.push({nums[j], j});

            if(j - i + 1  < k){
                // do nothing, as the window size is not met
            }else{
                // window size met
                // now until you find the max value which is under the max limit that we can go back
                // i.e for an index j, we can go back k elements
                // i.e the top should lie in [j - k + 1, j]
                while(!pq.empty() && pq.top().second < j - k + 1){
                    // removing the outdated elements
                    pq.pop();
                }

                // now the element found: inside the limits and the first max in the array
                // add inside the array
                ans.push_back(pq.top().first);

                // since window size is met, keep incrementing i
                i++;
            }
            j++;
        }

        return ans; 
    }
};
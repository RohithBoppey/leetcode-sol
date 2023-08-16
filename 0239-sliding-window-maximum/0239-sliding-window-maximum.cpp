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
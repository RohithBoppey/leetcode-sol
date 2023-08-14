class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // using the concept of min heap
        // at some point only k elements needs to be present 
        // so that we can return in O(N) time
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        // always maintain k elements
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            q.push(nums[i]); // it will readjust
            if(q.size() > k){
                // remove the first lesser elements
                q.pop();
            }
        }
        
        return q.top();
        
    }
};
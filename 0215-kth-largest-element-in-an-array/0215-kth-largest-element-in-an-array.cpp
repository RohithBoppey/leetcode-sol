class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // using the concept of min heap 
        // at any point if I store only 2 elements, then the top points to the kth largest element
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto x: nums){
            pq.push(x);

            if(pq.size() > k){
                // remove the top min element to still retain the sorted last k values
                pq.pop();
            }
        }

        return pq.top();

    }
};
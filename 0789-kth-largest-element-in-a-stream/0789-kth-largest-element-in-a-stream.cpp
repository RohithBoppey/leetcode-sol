class KthLargest {
public:
    int limit;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        limit = k;

        for(auto &x: nums){
            pq.push(x);

            if (pq.size() > k){
                // limit reached
                pq.pop();
            }
        }
    }

    int add(int x) {
        pq.push(x);
        int top = pq.top();
        if (pq.size() > limit){
            // limit reached
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
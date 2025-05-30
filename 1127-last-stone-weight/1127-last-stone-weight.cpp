class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // using max heap to always have max heavy stones handy
        // and re-insertion would be easier

        int n = stones.size(); 
        if(n == 1){
            return stones[0];
        }

        // max heap
        priority_queue<int> pq;

        for(auto &s: stones){
            pq.push(s);
        } 

        // start picking the stones from now
        while(pq.size() >= 2){
            // pick the top 2
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x != y){
                // x is getting destroyed and y's weight is changing
                pq.push(y - x);
            } 
        }

        // either 0 or 1
        return (pq.size() == 1) ? pq.top() : 0;
    }
};

![WhatsApp Image 2025-08-13 at 12 10 19_44697065](https://github.com/user-attachments/assets/70b7ee8c-82ff-4fda-a259-ab8089ffe113)


```c++
class Solution {
public:

    priority_queue<int> pq;
    int n; 
    int solve(vector<int>& v, int b, int l){
        n = v.size(); 

        int start = 0;

        while(start < n - 1){
            // cout << v[start] << endl;
            if(v[start] >= v[start + 1]){
                // can jump directly
                start++;
            }else{
                // you will need a ladder or bricks
                int diff = v[start + 1] - v[start];

                // first use bricks
                b -= diff; 
                pq.push(abs(diff));

                if(b < 0 and l > 0){
                    // maybe we can use a ladder near the previously max height seen so far
                    int top = pq.top();
                    pq.pop(); 
                    b += top; 
                    l--; 
                }

                if(b < 0 and l <= 0){
                    // no way to proceed
                    return start; 
                }
                start++;
            }
        }

        return start; 

    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return solve(heights, bricks, ladders);
    }
};
```

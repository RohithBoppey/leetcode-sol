https://practice.geeksforgeeks.org/contest/gfg-weekly-195-rated-contest/problems    
![WhatsApp Image 2025-02-26 at 08 53 26_78a831a4](https://github.com/user-attachments/assets/354795b5-16e0-424f-b5e8-cc21c5f7edc1)    
    
```c++
class Solution {
  public:
    int n;
  
    /*
    with the time limit, find number of agents required
    */
    int findNumberOfD(vector<int>& house, int limit){
        int d = 1;
        
        int last = 0, t = 0, ct = 0;
        
        for(int i: house){
            
            // time to deliver to this house
            ct = i - last + 2;
            
            // can add if it is under the limit
            if(t + ct <= limit){
                t = t + ct;
            }
            else{
                // use a new agent to deliver to this house
                ct = i + 2;
                d++;
                t = ct;
            }
            
            // update the last delivered house
            last = i;
        }
        
        return d;
    }
  
  
    long long minTime(vector<int>& house, int d) {
        // code here

        // using binary search to solve the problem
        
        // for the min limit, it will be max(arr) + 2
        // reason: pickup 1, walk = distance - 0 = distance, delivery 1
        // so dist + 2 == max(arr) + 2
        
        sort(house.begin(), house.end());
        
        // mx;
        n = house.size();
        
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, house[i]);
        }
        
        long long low = mx + 2, high = INT_MAX, mid;
        
        while(low < high){
            mid = low + (high - low) / 2;
            
            // with mid as the max time limit, find the number of delivery agents it will take to cover all
            int rd = findNumberOfD(house, mid);
            
            if(rd <= d){
                // with the current time limit & d agents, we can reach
                // so we can further reduce the time limit to utilise the agents more or can use this
                high = mid;
            }else{
                // we are not able to deliver to all houses
                // require more agents, so increase the time limit
                // MUST INCREASE
                low = mid + 1;
            }
        }
        
        return low;
        
    }
};
```



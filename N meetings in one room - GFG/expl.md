![WhatsApp Image 2023-07-17 at 15 39 17](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/ae16f2cf-3913-4ad2-bf6d-e306ea40226e)

```

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> duration;
        
        // we are inserting in [end, start] fashion
        // so that sorting would be easier
        
        for(int i = 0; i < n; i++){
            duration.push_back({end[i], start[i]});
        }
        
        // once the interval time is known
        // sort
        
        sort(duration.begin(), duration.end());
        
        
        int endTime = -1; // this measures when the last meeting has ended
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            
            // duration[i] = [end[i], start[i]]
            
            if(duration[i].second > endTime){
                // meeting is possible
                ans++;
                endTime = duration[i].first; // updating the new meeting time
            }
            
        }
        
        return ans;
        
    }
};
```

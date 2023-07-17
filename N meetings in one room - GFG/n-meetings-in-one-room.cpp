//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


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




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
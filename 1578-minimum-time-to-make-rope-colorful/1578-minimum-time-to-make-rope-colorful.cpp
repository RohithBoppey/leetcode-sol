class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        
        int n = colors.size();
        
        // we need to burst ballons such that there is no adjancency in the balloons
        
        int totalTime = 0;
        
        int i = 0;
        
        int curr, prev = 0, time;
        
        while(i < n){
            
            if(i > 0 && colors[i] != colors[i - 1]){
                // means there is no dependency
                prev = 0;
            }
            
            
            // time taken to burst the min one
            time = min(neededTime[i], prev);
            totalTime += time;
            
            // update the previous based on the curr
            // because previous is the retained ballon
            prev = max(neededTime[i], prev);
            
            // updating the index
            i++;
            
        }
        
        return totalTime;
    }
};
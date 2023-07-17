![WhatsApp Image 2023-07-17 at 14 57 19](https://user-images.githubusercontent.com/73538974/253902363-0f5052d5-93af-4973-b035-c6c5cab9016a.jpg)
![WhatsApp Image 2023-07-17 at 14 57 20](https://user-images.githubusercontent.com/73538974/253902369-6d225fbc-c747-49fa-89c5-f397e23feed9.jpg)

DRY RUN:      

![image](https://user-images.githubusercontent.com/73538974/253900432-b8a12bcb-6ebd-439d-9dcd-1855ec8785d6.png)
![image](https://user-images.githubusercontent.com/73538974/253900458-007e94dc-08dc-4000-a56d-f8f6d66ff0a3.png)
![image](https://user-images.githubusercontent.com/73538974/253900486-068b5d97-dd0e-43ce-9bad-e3a723f71f61.png)
![image](https://user-images.githubusercontent.com/73538974/253900522-066480ec-b127-497c-88d6-6ff4e54245e9.png)
![image](https://user-images.githubusercontent.com/73538974/253900539-1e70e519-8754-4861-876a-21ab51a3afeb.png)
![image](https://user-images.githubusercontent.com/73538974/253900560-60d6b376-4589-4f05-a760-c437fbe4757b.png)

```
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
```

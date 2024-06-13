ASKED BY **GOOGLE**
      
Basic soltuion: 38/78 passed ✅     

```
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        
        // SORTING is required
        sort(people.begin(), people.end());
        
        int boats = 1, curr = limit, i = 0;
        
        while(i < n){
            
            if(curr >= people[i]){
                // can fit
                curr -= people[i];
                i++;
            }    
            else{
                // less limit
                // we need a new boat
                boats++;
                curr = limit; 
            }
            
        }
        
        return boats;
        
    }
};
```

Missed observation: 2 people in one boat and should put one heavy and one light person in one boat        
Intuition: So using 2 pointer approach.  78/78 passed ✅    
      
![WhatsApp Image 2023-07-17 at 12 43 06](https://user-images.githubusercontent.com/73538974/253874386-e1e5c42b-c8a5-48ee-a8e8-cc9b26f121d2.jpg)     
      
```
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int boats = 0; // initial boats
        
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        // now fill with one heavy and one light person
        
        int i = 0, j = n - 1;
        
        while(i < j){
            
            if(people[i] + people[j] <= limit){
                // can fit 2 in one boat
                boats++;
                i++;
                j--;
            }else{
                // less than limit
                // send the final person in a single boat
                boats++;
                j--;
            }
        }
    
        if(i == j){
            // single person is left
            // so send in seperate boat
            boats++;
        }
        
        return boats;
        
    }
};
```
​

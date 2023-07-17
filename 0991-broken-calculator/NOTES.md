Asked in **Samsung**

This is not the optimal solution because there are many many paths!     
      
![image](https://user-images.githubusercontent.com/73538974/253878381-53367634-4252-4614-9102-f7edb1ed0b81.png)           
![image](https://user-images.githubusercontent.com/73538974/253878541-18bea480-6a19-47b3-a1ed-7a78ba0b61dd.png)    

Instead of bfs, we can use greedy approach!     
            
![WhatsApp Image 2023-07-17 at 13 16 48](https://user-images.githubusercontent.com/73538974/253882047-9242cda8-9aee-412f-b038-2f7a263d2fa6.jpg)     
      
DRY RUN:      
      
![image](https://user-images.githubusercontent.com/73538974/253879025-d1f30b5f-9b3f-46d3-8b62-6631fb0759d3.png)       
![image](https://user-images.githubusercontent.com/73538974/253878962-2b6eb215-3940-4ef6-997d-43a0eff64ea3.png)         
          

```
class Solution {
public:
    int brokenCalc(int start, int target) {
        
        if(start >= target){
            // we are just adding 1 to target for n number of steps
            // example: start: 23 target: 17 -> required 6 +1's or -1's
            return (start - target);
        }
        
        // recursively divide the number whenever it is possible
        // else add 1
        
        if(target % 2 == 0){
            // even
            return 1 + brokenCalc(start, target / 2);
        }
        else{
            // odd
            return 1 + brokenCalc(start, target + 1);
        }
        
        // dummy
        return -1;
        
    }
};
```

​

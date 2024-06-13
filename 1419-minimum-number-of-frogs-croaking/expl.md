​![WhatsApp Image 2023-07-17 at 16 41 22](https://user-images.githubusercontent.com/73538974/253924072-40dbff2f-67e3-4bd7-a771-7590d5e35992.jpg)
      
      
DRY RUN: --------      
        
![image](https://user-images.githubusercontent.com/73538974/253924207-85b7e4a5-8ff7-4c8a-97ba-c50f0ec83b55.png)
![image](https://user-images.githubusercontent.com/73538974/253924235-0dd245d4-3bfe-4fad-85b6-cea9f4d50657.png)
![image](https://user-images.githubusercontent.com/73538974/253924258-98c19d65-85a9-4fa4-8773-3322ee4e3eef.png)
![image](https://user-images.githubusercontent.com/73538974/253924285-f790c023-0964-4f24-9f7b-20742f596582.png)
![image](https://user-images.githubusercontent.com/73538974/253924318-3c1d6588-36b6-4e53-ad64-8bcd1449132a.png)
![image](https://user-images.githubusercontent.com/73538974/253924339-fc13001a-6a5e-4fa9-943b-e52310a05fc8.png)
![image](https://user-images.githubusercontent.com/73538974/253924360-2426188b-5c3c-40d0-bd01-88c2a27a1bf4.png)
![image](https://user-images.githubusercontent.com/73538974/253924385-48347868-4766-490f-a65d-0bc65fd1ab66.png)
![image](https://user-images.githubusercontent.com/73538974/253924406-b8dd66e7-c1d0-45c6-97fe-158e4f97715a.png)
![image](https://user-images.githubusercontent.com/73538974/253924422-ee2146e6-b4db-4d21-8a97-86e5b29a326b.png)


![image](https://user-images.githubusercontent.com/73538974/253918849-6a5edac9-57c2-465e-bed5-d67d786d865a.png)

```
class Solution {
public:
    int minNumberOfFrogs(string s) {
        
        int n = s.size(); // s is a mix of croak workds
        
        string req = "croak";
        
        vector<int> freq(5, 0); // this vector counts number of occurances
        
        int mx = 0, curr = 0; // no of frogs
        
        int currIndex;
        
        for(int i = 0; i < n; i++){
            
            currIndex = req.find(s[i]);
            
            // based on this current index, I will be finding out number of frogs and so on
            
            freq[currIndex]++;
            
            if(currIndex == 0){
                // means 'c' -> start of a new frog singing
                curr++;
                mx = max(mx, curr);
            }
            
            else if(currIndex == 4){
                // last index -> 'k', means frog has stopped singing
                freq[currIndex]--;
                curr--;
            }
            
            if(currIndex > 0){
                // at all times, we need to check whether the prev character has been sang or not
                freq[currIndex - 1]--;
                
                if(freq[currIndex - 1] < 0){
                    
                    // that means some letter occured without previous one
                    return -1;
                }
            }
            
        }
        
        // now if the frogs == 0 means all frogs sang properly
        return (curr == 0) ? mx : -1;
        
    }
};
```

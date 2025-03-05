
![WhatsApp Image 2025-03-05 at 22 40 57_2a06a006](https://github.com/user-attachments/assets/145185e0-8faa-472b-9893-d8f9258be80e)


```c++
class Solution {
public:
    long long coloredCells(int n) {
        int start = 1;

        // need 2 variables
        long long colored, open;

        // initialise
        if(start == 1){
            colored = 1;
            open = 4;
        }

        while(start < n){
            // keep expanding the scope
            colored = colored + open;
            open += 4;
            start++;
        }

        return colored;
    }
};
```

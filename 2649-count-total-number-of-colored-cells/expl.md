


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

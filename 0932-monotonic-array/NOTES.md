If (n < 2) -> means that the numbers are either same or increasing or decreasing      
Trying to find the pattern for the first different numbers -> and then carrying out for the rest      
      
```
int start = 0;
while (start < n - 1) {
    if (nums[start] == nums[start + 1]) {
        start++;
    } else {
        break;
    }
}
```
      
This code is essential to check the starting numbers which are different -> when they are different, then from then we find the pattern, but if the start reaches (n - 1) means that the entire array contains the same number      
      
```
inc = (nums[start] < nums[start + 1]);
for (int i = start + 1; i < n - 1; i++) {
    if (nums[i] == nums[i + 1]) {
        continue;
    }
    check = (nums[i] < nums[i + 1]);
    if (check != inc) {
        return false;
    }
}
```
      
This code is responsible for checking if the pattern is increasing or decreasing!      
      

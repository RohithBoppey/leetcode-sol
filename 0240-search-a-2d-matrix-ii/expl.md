​2 pointers using low and high, we can solve this:       
      
![image](https://user-images.githubusercontent.com/73538974/270102183-f81919eb-5ec0-40d0-9cd1-49ea24b3b45f.png)
![image](https://user-images.githubusercontent.com/73538974/270102194-de154199-5ec4-4bc9-bb69-204fd70758ef.png)
![image](https://user-images.githubusercontent.com/73538974/270102198-5f59001f-5db1-47df-a8cd-e6c89e0aff27.png)

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int low = 0, high = cols - 1;
        
        while(low < rows && high >= 0){
            if(matrix[low][high] == target){
                return true;
            }
            else if(matrix[low][high] > target){
                // move left
                high--;
            }
            else{
                low++;
            }
        }
        
        return false;
    }
};
```

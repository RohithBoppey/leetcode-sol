​Assign ID for each numbers, and then do simple binary search.          
This is only possible because the numbers are in right sequence.      
      
![image](https://user-images.githubusercontent.com/73538974/270101385-d6b0044b-5949-458e-8c27-aa41acc49d11.png)
![image](https://user-images.githubusercontent.com/73538974/270101403-ac9fbeb6-f604-48cf-9136-43ad9016330c.png)

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // we have indexes from [0, n - 1]
        int left = 0, right = (rows*cols) - 1, mid;
        int row, col;
        
        while(left <= right){
            mid = left + (right - left) / 2;
            row = mid / cols;
            col = mid % cols;
            
            if(matrix[row][col] == target){
                // found
                return true;
            }
            
            else if(matrix[row][col] < target){
                // modify left
                left = mid + 1;
            }
            
            else{
                right = mid - 1;
            }
            
        }
        
        return false;
        
    }
};
```

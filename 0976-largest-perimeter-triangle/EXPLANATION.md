For a triangle to form - sum of 2 sides in a triangle > third side.
  
After sorting, from the last 3 entries, we can see if it forms a triangle and yes, break, else continue - sliding window appraoch  
Because in `[1,1,2,3,6]` - if the `[2,3,6]` window, if 2 can form the triangle with 6, then any number on the left can also form the triangle, in that case, max would be `[2,3,6]`. In this case, this combination failed, so there is no point in checking left.
  
```c++
class Solution {
public:
    
    int isATriangle(int a, int b, int c){
        if(a + b > c && a + c > b && c + a > b){
            return true;
        }
        return false;
    }
    
    
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        // from the sliding window approach
        // keep going left until you find the max first
        
        int perimeter = 0;
        
        int start = n - 3;
        
        while(start >= 0){
            if(isATriangle(nums[start], nums[start + 1], nums[start + 2])){
                // then is a triangle
                perimeter = nums[start] + nums[start + 1] + nums[start + 2];
                break;
            }
            start--;
        }
        
        return perimeter;
    }
};
```

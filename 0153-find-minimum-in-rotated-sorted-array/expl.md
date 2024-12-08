Trickly but simple solution using Binary Search. The idea is to find the breaking point, so that the minimum would be next to the breaking point. 

![image](https://github.com/user-attachments/assets/5068daf9-d899-4daa-9dda-237bf2128e87)
![image](https://github.com/user-attachments/assets/a02afe49-3d0c-4aa5-bba6-0c14c4b21f2e)

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n - 1, mid;

        // if left <= right, the loop keeps on going
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[right]){
                // breaking point is on the right
                left = mid + 1;
            }

            else {
                // the mid itself can be the minimum number
                right = mid;
            }
        }

        return nums[left];

    }
};
```

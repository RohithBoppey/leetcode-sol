​using 2 pointers and finding which are not equal

![WhatsApp Image 2023-07-13 at 16 03 32](https://user-images.githubusercontent.com/73538974/253248747-157ec0ed-8210-4bf5-a275-73164da5194f.jpg)

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); 

        // i always points to the index where until I know that unique elements exists
        // j pointer brings us the next unique element
        int i = 0, j = 1;

        while(j < n){
            if(nums[i] != nums[j]){
                // new unique element found, hence update the ith pointer
                nums[i + 1] = nums[j];
                i++;
            }
            j++;
        }

        return i + 1;
    }
};
```

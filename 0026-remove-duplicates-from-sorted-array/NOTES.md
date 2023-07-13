​using 2 pointers and finding which are not equal

![WhatsApp Image 2023-07-13 at 16 03 32](https://user-images.githubusercontent.com/73538974/253248747-157ec0ed-8210-4bf5-a275-73164da5194f.jpg)

```
int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        
        while(j < n){
            if(nums[i] != nums[j]){
                // not equal
                nums[i + 1] = nums[j];
                i++;
            }
            j++;
        }
        
        return i + 1;
        
    }
```

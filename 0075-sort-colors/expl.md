Intuition: 
![WhatsApp Image 2025-03-03 at 23 04 28_cab77f27](https://github.com/user-attachments/assets/250c490b-f9a3-4e35-b3cd-d31d7f30871d)
![WhatsApp Image 2025-03-03 at 23 05 00_0e7f44ac](https://github.com/user-attachments/assets/37179159-9c38-4b5d-9373-93066b5ba2d3)


having 3 pointers low, mid and high and follows simple logic
​
```
[0, low - 1] => 0
[low, mid - 1] => 1
[mid, high] => unsorted array -> this is the only part we need to solve
[high + 1, n - 1] => 2
```
Dry run:
​  
![image](https://user-images.githubusercontent.com/73538974/248544178-c3ba5fa5-a77b-4166-a2b8-9674acdce7b6.png)
​  
```c++
class Solution {
public:
    int n;

    void sortColors(vector<int>& nums) {
        n=nums.size();
        int i=0, j=0, k=n-1;

        // j is the current looper in the array
        while(j<=k){
            if(nums[j]==0){
                // 0 to i-1 should be 0, swap with i
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else if(nums[j]==1){
                j++;
            }else{
                // k
                // since k+1 to j everything should be 2
                swap(nums[j],nums[k]);
                k--;
            }
        }

        return;
    }
};
```

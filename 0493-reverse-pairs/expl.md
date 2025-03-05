follow similar algoirthm to [inversion count](https://www.codingninjas.com/studio/problems/count-inversions_615)
but the fundamental difference is near merging, in inversion count, we are just seeing greater than, hence we can break in one loop
but here we need to find nums[i] > 2 * nums[j], so we need to find the right element for which all the left are possible
![image](https://user-images.githubusercontent.com/73538974/250906504-118c24b1-8dc9-437d-a5d6-8330c1b6ec52.png)
in this image, we are finding the correct right posisiton for which it is failing, and the left of right_pointer is satisfied by all the number of the right
we are retaining the count and adding, hence this is optimal
![WhatsApp Image 2023-07-04 at 18 19 25](https://user-images.githubusercontent.com/73538974/250905859-16f3d311-51a2-495c-bfbf-442b3825f387.jpg)

Count funciton Logic: 
![WhatsApp Image 2025-03-05 at 22 40 07_9879243e](https://github.com/user-attachments/assets/69ec715d-af5b-4ae0-ae50-0735301e0c3e)


```c++
class Solution {
public:
    int ans, n;

    void combine(vector<int>& v, int low, int mid, int high){
        // now the left and right parts in this vector are already sorted, just combine them
        // copy back in the array in place

        if(low >= high){
            // already in place
            return;
        }

        int lp = low, rp = mid + 1;
        vector<int> t;

        while(lp <= mid && rp <= high){
            if(v[lp] <= v[rp]){
                // move left
                t.push_back(v[lp]);
                lp++;
            }
            else{  
                // move right
                t.push_back(v[rp]);
                rp++;
            }
        }

        // remaining
        while(lp <= mid){
            t.push_back(v[lp]);
            lp++;
        }

        while(rp <= high){
            t.push_back(v[rp]);
            rp++;
        }

        // now copy back in the original array
        // COPY FROM LOW TO HIGH - but the t is relative
        for(int i = low; i <= high; i++){
            v[i] = t[i - low];
        }

    }

    void findCount(vector<int>& v, int low, int mid, int high){
        // we have 2 sorted arrays here before combining, so use that logic
        int lp = low, rp = mid + 1;

        while (lp <= mid) {
            while (rp <= high && (long long)v[lp] > 2LL * v[rp]) {
                rp++;
            }
            ans += (rp - (mid + 1)); // Count valid pairs for v[lp]
            lp++;
        }
    }

    void mergeSort(vector<int>& v, int low, int high){
        // this function will split into left & right, sort them individually and then merge back into the main array
        // at the end, you will be having the fully sorted array from low to high

        if(low >= high){
            // nothing to sort
            return;
        }

        int mid = low + (high - low) / 2;

        // sort left
        mergeSort(v, low, mid);

        // sort right
        mergeSort(v, mid + 1, high);

        // add to the count
        findCount(v, low, mid, high);

        // combine both the sorted parts -> copy into the array
        combine(v, low, mid, high);

    }


    int reversePairs(vector<int>& nums) {
        // using merge sort logic to sort the array
        ans = 0;
        n = nums.size();

        mergeSort(nums, 0, n - 1);

        // for(auto x: nums){
        //     cout << x << " ";
        // }
        // cout << endl;

        return ans;
    }
};
```
​
​

Proper Merge Sort question: 

![WhatsApp Image 2025-03-05 at 22 40 35_52d7aa6b](https://github.com/user-attachments/assets/468bd86c-538c-4c8d-8100-e26ecd6dc4b9)

```c++
class Solution {
public:
    int n;

    void mergeBoth(vector<int>& v, int low, int high, int mid){
        // take both the array and put in back in the array
        vector<int> temp;

        int lp = low, rp = mid + 1;

        // the ranges for the pointers are [low, mid] & [mid + 1, high]
        while(lp <= mid && rp <= high){
            // compare and proceed
            if(v[lp] < v[rp]){
                // move left
                temp.push_back(v[lp]);
                lp++;
            }else{
                // move right
                temp.push_back(v[rp]);
                rp++;
            }
        }

        // copy the remaining elements
        while(lp <= mid){
            temp.push_back(v[lp]);
            lp++;
        }

        while(rp <= high){
            temp.push_back(v[rp]);
            rp++;
        }

        // now both are copied, come back to the previous array
        for(int i = low; i <= high; i++){
            v[i] = temp[i - low];
        }

    }

    void sortRec(vector<int>& v, int low, int high){
        
        if(low >= high){
            // single elment or no elements
            // nothing to sort
            return;
        }


        int mid;

        mid = low + (high - low) / 2;

        // sort the left side of the array
        sortRec(v, low, mid);

        // sort the right part of the array
        sortRec(v, mid + 1, high);

        // merge both the parts now
        mergeBoth(v, low, high, mid);
        
    
    }


    vector<int> sortArray(vector<int>& nums) {
        // using merge sort to solve the problem
        n =  nums.size();
        sortRec(nums, 0, n - 1);
        return nums;

    }
};
```


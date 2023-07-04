class Solution {
public:
    // new
    void merge(vector<int>& v, int low, int mid, int high){
        // we already have left and right parts sorted
        // the only function this does is merging

        int left_pointer = low, right_pointer = mid + 1;
    
        // left - [low, mid] & right - [mid + 1, high]

        vector<int> temp;

        while(left_pointer <= mid && right_pointer <= high){
            // is a valid index
            if(v[left_pointer] <= v[right_pointer]){
                temp.push_back(v[left_pointer]);
                left_pointer++;
            }else{
                temp.push_back(v[right_pointer]);
                right_pointer++;
            }
        }

        // copying the remaining elements
        while(left_pointer <= mid){
            temp.push_back(v[left_pointer]);
            left_pointer++;
        }

        while(right_pointer <= high){
            temp.push_back(v[right_pointer]);
            right_pointer++;
        }

        // copying back
        for(int i = low; i <= high; i++){
            v[i] = temp[i - low];
        }
    }
    
    int findCount(vector<int>& v, int low, int mid, int high){
        // now you have left and right arrays without sorting
        int count = 0;
        int left_pointer = low, right_pointer = mid + 1;
        for(left_pointer = low; left_pointer <= mid; left_pointer++){
            // move right to the correct position
            while(right_pointer <= high && (long long int) v[left_pointer] > (long long int) 2 * v[right_pointer]){
                right_pointer++;
            }
            
            // add the persisting count
            count += right_pointer - (mid + 1);
        }
        return count;
    }
    
    int helper(vector<int>& v, int low, int high){
        if(low >= high){
            // single element
            return 0;
        }

        int mid = low + ((high - low) / 2);
        // sorting left one, sorting right one, and then merging

        // should return the count
        int count = 0;
        
        // sorting left
        count += helper(v, low, mid);
        // sorting right
        count += helper(v, mid + 1, high);
    
        count += findCount(v, low, mid, high);
        
        // merging left and right
        merge(v, low, mid, high);
        
        return count;
    }

    int mergeSort(vector<int> &v){
        int n = v.size();
        int low = 0, high = n - 1;
        return helper(v, low, high);
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums);
    }
};
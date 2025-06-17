class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // using pointers for tracking positions and insertion
        int seen = m - 1; // last known pointer in the nums 1
        int r = n - 1; // last max value in the nums 2
        int to = m + n - 1; // which posititon to insert starting from the end

        // this loop can run until either of the pointer is null
        // if r pointer is null, all elements are inserted into the main array
        // if r is not null, that means there are some elements in the nums2 which are less than the least element in nums1 i.e. should be inserted at the start
        while(seen >= 0 && r >= 0){
            if(nums1[seen] < nums2[r]){
                // should be inserted at the end
                nums1[to] = nums2[r];
                r--;
            }else{
                // nums1[seen] >= nums2[r]
                // fill the value in the nums1 itself
                nums1[to] = nums1[seen];
                seen--; 
            }
            to--;
        }

        // now there might be remaining elements in the r
        while(r >= 0){
            // fill the nums1 with to
            nums1[to] = nums2[r];
            r--;
            to--;
        }
    }
};
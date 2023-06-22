class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // using binary search
        
        // given sorted arrays both
        double ans = 0.0;
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // better to go with smaller first
        if(n2 < n1) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int l1,l2,h1,h2,low,high,cut1,cut2;
        
        low = 0, high = n1;
        
        while(low <= high){
            cut1 = low + ((high - low) / 2);
            cut2 = ((n1 + n2 + 1) / 2) - cut1;
            
            // populating l1, l2, h1, h2;
            
            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            
            h1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            h2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            
            
            if(l1 <= h2 && l2 <= h1){
                // is valid
                if((n1 + n2) % 2 == 0){
                    // even
                    return (double)(max(l1, l2) + min(h1, h2)) / 2.0;
                }else{
                    // odd
                    // just a single element
                    return max(l1, l2);
                }
            }else{
                // we need to change the low and high
                if(l1 > h2){
                    // we gotta move left
                    high = cut1 - 1;
                }else{
                    low = cut1 + 1;
                }
            }            
        }
        
        return ans;
    }
};




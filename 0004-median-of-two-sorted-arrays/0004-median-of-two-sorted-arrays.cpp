class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans = 0.0;
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // always dealing with min length array
        if(n2 < n1){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int cut1 = 0, cut2 = 0;
        int low = 0, high = n1, mid = 0;
        
        int l1, l2, r1, r2;
        
        // find the valid partition
        while(1){
            mid = low + ((high - low) / 2);
            cut1 = mid;
            cut2 = ((n1 + n2) / 2) - cut1;
            
            // find l1, l2
            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            
            if(l1 > r2){
                // cut1 to the right
                high = mid - 1;
            }
            
            else if(l2 > r1){
                // cut1 to the left
                low = mid + 1;
            }
            
            else if(l1 <= r2 && l2 <= r1){
                // valid partition
                // cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
                break;
            }
        }
        
        
        ans = ((n1 + n2) % 2 == 0) ? 
            (double)(max(l1,l2) + min(r1,r2)) / 2 
            :
            (double)min(r1,r2);
        
        return ans;
        
    }
};
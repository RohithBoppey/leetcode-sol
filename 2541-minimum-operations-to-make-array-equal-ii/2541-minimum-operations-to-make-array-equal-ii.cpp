class Solution {
public:
    
    int isEqual(vector<int>& v1, vector<int>& v2){
        int n = v1.size();
        
        for(int i = 0; i < n; i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        
        return true;
    }
    
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {        
        int n = nums1.size();
        
        long long sum = 0, diff = 0;
        
        if(isEqual(nums1, nums2)){
            return 0;
        }
        
        if(k == 0) return -1;
        
        for(int i = 0; i < n; i++){
            if(nums1[i] > nums2[i]){
                if(
                    (nums1[i] - nums2[i]) % k == 0
                ){
                    diff += (nums1[i] - nums2[i]) / k;
                }else{
                    return -1;
                }
            }
            else if(nums1[i] < nums2[i]){
                if(
                    (nums2[i] - nums1[i]) % k == 0
                ){
                    sum += (nums2[i] - nums1[i]) / k;
                }else{
                    return -1;
                }
            }
        }
        
        return (sum == diff) ? sum : -1;
    }
};
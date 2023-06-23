class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int> t(1001, 0);
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j] and t[nums1[i]] != 1){
                    // found
                    result.push_back(nums1[i]);
                    t[nums1[i]] = 1;
                    break;
                }
            }
        }
        return result;
    }
};
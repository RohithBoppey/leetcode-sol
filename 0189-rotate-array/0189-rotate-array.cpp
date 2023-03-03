class Solution {
public:
    
    void rotateArray(vector<int> &v, int k){
        int n = v.size();
        if(k % n == 0){
            return;
        }
        if(k > n){
            k = k % n;
        }
        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
    }

    void rotate(vector<int>& nums, int k) {
        rotateArray(nums, k);
    }
};
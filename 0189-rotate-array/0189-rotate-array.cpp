class Solution {
public:
    
    vector<int> rotateArray(vector<int> &v, int k){
        int n = v.size();
        if(k % n == 0){
            // no rotation required
            return v;
        }

        k = k % n;

        vector<int> res(n, 0);

        // 2 parts
        // first part contains last k elements in order
        int t = 0;
        for(int i = n - k; i < n; i++){
            res[t] = v[i];
            t++;
        }

        // second part contains first n - k elements in order
        for(int i = 0; i < n - k; i++){
            res[t] = v[i];
            t++;
        }

        return res;
    }

    void rotate(vector<int>& nums, int k) {
        vector<int> res = rotateArray(nums, k);
        for(int i = 0; i < res.size(); i++){
            nums[i] = res[i];
        }
    }
};
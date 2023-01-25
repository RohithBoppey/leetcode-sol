class Solution {
public:
    void print(vector<int> v){
        for(auto x: v){
            cout << x << " ";;
        }
        cout << endl;
    }


    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1){
            return true;
        }
        vector<int> v(2 * n);
        for(int i = 0; i < n; i++){
            v[i] = nums[i]; 
            v[n + i] = v[i];
        }
        sort(nums.begin(), nums.end());
        // print(v);
        auto it = search(v.begin(), v.end(), nums.begin(), nums.end());
        return (it != v.end()) ? true : false;
    }
};
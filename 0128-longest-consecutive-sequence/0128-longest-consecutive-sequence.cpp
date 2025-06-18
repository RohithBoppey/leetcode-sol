class Solution {
public:
    int n;
    map<int, int> mp;

    int longestConsecutive(vector<int>& nums) {
        n = nums.size(); 
        int ans = 0;
        for(auto &x: nums){
            mp[x]++;
        }    

        int start = INT_MIN, next = INT_MIN;
        int val;
        for(auto &it: mp){
            // cout << it.first << endl;
            val = it.first;
            if(start == INT_MIN || next == INT_MIN){
                // started just now, base condition
                start = val;
                next = val + 1;
                ans = 1; // since default is one
            }else{ 
                if(val == next){
                    // next element found
                    ans = max(ans, next - start + 1);
                    next++;
                }else{
                    start = val;
                    next = val + 1;
                }
            }
        }

        return ans;
    }
};
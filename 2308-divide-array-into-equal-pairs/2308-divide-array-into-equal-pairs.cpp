class Solution {
public:

    void printV(vector<int>& v){
        for(auto s: v){
            cout << s << " ";
        }
    }

    bool divideArray(vector<int>& nums) {
        // if equal divide -> XOR should be 0
        int ans = 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if(n % 2){
            return false;
        }

        ans = 0;
        for(int i = 0; i < n - 1; i += 2){
            // take pair wise and do xor
            ans = nums[i] ^ nums[i + 1];
            if(ans != 0){
                return false;
            }
        }

        return ans == 0;
    }
};
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        for (int i = 1, j = 0; i <= 1000 && j < nums.size(); i++) {
          if (nums[j] == i) {
            j++;
          } else {
            k--;
            if (k == 0) {
              return i;
            }
          }
        }
        return nums[nums.size() - 1] + k;
    }
};
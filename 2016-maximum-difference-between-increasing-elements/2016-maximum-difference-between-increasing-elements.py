def greatest_right(nums):
    n = len(nums)
    arr = [0] * n
    mx = -1
    for i in range(n - 1, -1, -1):
        arr[i] = mx
        mx = max(mx, nums[i])
    return arr

class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ng = greatest_right(nums)
        # print(ng)
        ans = -1
        for i in range(0, n):
            val = max(ans, ng[i] - nums[i])
            ans = val if val > 0 else ans
        return ans
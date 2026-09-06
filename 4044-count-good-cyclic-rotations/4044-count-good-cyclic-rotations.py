class Solution:
    def countGoodRotations(self, nums: list[int]) -> int:
        n = len(nums)
        f,s = 0,0
        for i in range(n // 2): 
            f += nums[i]
            s += nums[(n // 2) + i]

        ans = 0
        fi, li = (n // 2) - 1, n - 1
        for i in range(n): 
            # print(f, s, fi, li)
            if f > s: 
                ans += 1
            
            # rotate 
            f += nums[li] - nums[fi]
            s += nums[fi] - nums[li]

            fi = (fi - 1) % n
            li = (li - 1) % n

        return ans





# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
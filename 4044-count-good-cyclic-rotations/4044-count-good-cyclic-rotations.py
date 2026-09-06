class Solution:
    def countGoodRotations(self, nums: list[int]) -> int:
        n = len(nums)

        sm = sum(nums)
        rn = 0
        i,j = 0,0 

        for i in range(n // 2):
            rn += nums[i]
            j += 1

        ans = 0
        i = 0
        c = n - 1
        
        while c >= 0: 
            print(rn)
            if rn > sm - rn: 
                ans += 1

            rn += nums[j % n] - nums[i % n]
            j += 1
            i += 1
            c -= 1

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
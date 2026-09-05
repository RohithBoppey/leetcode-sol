class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        mina, maxa = [-1]*n, [nums[0]]
        mina[n - 1] = nums[n - 1]

        for i in range(1, n): 
            maxa.append(max(maxa[i - 1], nums[i]))

        for i in range(n - 2, -1, -1): 
            mina[i] = min(mina[i+1], nums[i])

        # print(mina, maxa)

        for i in range(n): 
            st = maxa[i] - mina[i]
            if st <= k:
                return i

        return -1


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
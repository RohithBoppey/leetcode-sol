class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        mp = {}
        for i in nums:
            mp[i] = 1
        for i in range(1, 1000):
            if not mp.get(k * i):
                return k * i
        
        return -1


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
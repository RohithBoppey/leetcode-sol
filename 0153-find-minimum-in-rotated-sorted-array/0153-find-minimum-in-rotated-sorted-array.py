class Solution:
    def findMin(self, nums: List[int]) -> int:
        mn = math.inf
        for i in nums: 
            mn = min(mn, i)
        return mn

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
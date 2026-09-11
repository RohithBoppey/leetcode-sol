class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [-math.inf] + nums + [-math.inf]
        # print(arr)
        for i in range(1, n+1):
            # middle
            if arr[i] > arr[i-1] and arr[i] > arr[i+1]: 
                return i-1
        # first or last
        return 0 if (n == 1) else n-1

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
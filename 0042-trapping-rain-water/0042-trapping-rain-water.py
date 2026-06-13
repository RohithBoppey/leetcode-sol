class Solution:
    def trap(self, height: List[int]) -> int:
        # max to the left and right 
        n = len(height)
        left = [0]*n
        right = [0]*n
        
        # left
        left[0] = height[0]
        for i in range(1, n): 
            left[i] = max(height[i], left[i - 1])

        # right
        right[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            right[i] = max(height[i], right[i + 1])

        # print(left, right)

        w = 0

        for i in range(n):
            w += abs( min(left[i], right[i]) - height[i])

        return w

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
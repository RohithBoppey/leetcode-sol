class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        l, r = 0, n - 1
        ans = 0

        while (l < r):
            w = (r - l)
            mx = min(height[l], height[r])
            ans = max(ans, mx * w)

            if height[l] < height[r]:
                # can go to right, so that I can find a better height
                l += 1
            else:
                r -= 1 

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
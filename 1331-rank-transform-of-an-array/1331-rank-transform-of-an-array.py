class Solution:
    def arrayRankTransform(self, arr):
        rank = {}

        for i, num in enumerate(sorted(set(arr))):
            rank[num] = i + 1

        return [rank[x] for x in arr]

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
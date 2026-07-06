class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        # custom sort condition is required
        intervals.sort(key = lambda x: (x[0], -x[1]))
        ans, n = 0, len(intervals)
        max_end = -math.inf
        
        for i in intervals:
            if max_end >= i[1]:
                # already might have seen this
                ans += 1
            else: 
                max_end = i[1]

        return n - ans


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
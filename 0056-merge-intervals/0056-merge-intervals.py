class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # sort on the start position
        intervals.sort() 
        ans = []
        n = len(intervals)

        start, end = intervals[0][0], intervals[0][1]
        
        for i in range(1, n):
            # compare with the next start position with the current one
            if intervals[i][0] <= end: 
                end = max(end, intervals[i][1])
            else:
                # then seperate the ones
                ans.append([start, end]) 
                start, end = intervals[i][0], intervals[i][1]

        # add the last remaining ones
        ans.append([start, end])

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        # start from left and find the distinct color from the right 
        n = len(colors)
        ans = 0
        for i in range(0, n): 
            c = colors[i]
            j = n - 1
            while j > i and colors[j] == c:
                j -= 1
            # now j points to an index which is having a different color than i
            ans = max(ans, j - i)
        return ans
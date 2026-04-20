class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        res = 0
        
        # Case 1: Distance from the first house to the furthest different color from the right
        for j in range(n - 1, 0, -1):
            if colors[0] != colors[j]:
                res = max(res, j)
                break
                
        # Case 2: Distance from the last house to the furthest different color from the left
        for i in range(0, n - 1):
            if colors[n - 1] != colors[i]:
                res = max(res, n - 1 - i)
                break 
        return res
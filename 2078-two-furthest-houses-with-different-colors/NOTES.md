First idea is get the 2 distinct houses from the left and the right (but this is O(N2))

```py
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
```

Cache enabled approach: 

```py
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        # start from left and find the distinct color from the right 
        n = len(colors)
        ans = 0
        
        # with caching 
        ch = {}
        for i in range(0, n - 1):
            c = colors[i]
            if ch.get(c) is not None: 
                continue 
            j = n - 1
            while j > i and colors[j] == c:
                j -= 1
            # now j points to an index which is having a different color than i
            ans = max(ans, j - i)
            ch[c] = ch.get(c, 0) + 1

        return ans
```

Final optimized approach (since the only values possible are: first house to the last or last house to the first) ✅

```py
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
```

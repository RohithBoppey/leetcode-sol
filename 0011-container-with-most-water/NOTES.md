
<img width="801" height="383" alt="image" src="https://github.com/user-attachments/assets/da1e499b-7a32-4ec4-aabb-4fe7f1e0388e" />
- if you are comparing all indices - O(N2)
- but if you fix 2 indices - left and right, then the max water that can be possible is always constrained by the min height of the both
- and we can always increase from least height direction because there is chance of finding a better height then! 
  
```py
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
```

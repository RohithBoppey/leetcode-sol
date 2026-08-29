def solve(m, b, l, h): 
    diff = []
    for i in range(m): 
        d = h[i + 1] - h[i]
        if d > 0:
            diff.append(d)
    diff.sort(reverse=True) 

    # use ladders first
    i = 0
    while l > 0:
        i += 1
        l -= 1
    
    # use bricks
    while i < len(diff): 
        b -= diff[i]
        i += 1

    return b >= 0 

    

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        # binary search 
        n = len(heights)

        low, high, mid = 0, n - 1, 0

        while low <= high: 
            mid = low + (high - low) // 2
            if solve(mid, bricks, ladders, heights) == True: 
                # keep this, but can also move further
                low = mid + 1
            else: 
                high = mid - 1

        return high

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        # always use ladder first, and then fix with bricks later
        # min heap to always store at what min height we used a ladder
        n = len(heights)
        pq = []

        for i in range(0, n - 1):
            d = heights[i + 1] - heights[i]
            if d <= 0:
                # nothing is required
                continue
            
            # use ladder
            heapq.heappush(pq, d)

            if len(pq) > ladders: 
                # should remove min height ladder and replace with bricks
                md = heapq.heappop(pq)
                bricks -= md
                if bricks < 0:
                    return i 

        return n - 1

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
import heapq

class Solution:
    def minMeetingRooms(self, start, end):
        # code here
        n = len(start)
        pq = []
        
        intr = []
        for i in range(n): 
            intr.append([start[i], end[i]])
            
        intr.sort(key = lambda x: x[0])
        
        for i in range(n):
            if len(pq) == 0 or pq[0] > intr[i][0]:
                # require more meeting rooms
                heapq.heappush(pq, intr[i][1])
            else: 
                # can reuse the first popping meeting room
                heapq.heappop(pq)
                heapq.heappush(pq, intr[i][1])
                
        
        return len(pq)
        


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
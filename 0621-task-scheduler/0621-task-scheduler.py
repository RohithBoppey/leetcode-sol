class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        dc = {}
        for i in tasks: 
            if dc.get(i) is None: 
                dc[i] = 0
            dc[i] += 1

        k = max(dc.values())
        m = 0
        for i in dc: 
            if dc[i] == k: 
                m += 1
        
        return max(len(tasks), ((k - 1) * (n + 1)) + m)
        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        final = []
        for i in trips: 
            final.append([i[1], i[0]])
            final.append([i[2], -i[0]])
        
        final.sort(key = lambda x : (x[0], x[1])) 
        # print(final)
        curr = 0 
        for i in final: 
            curr += i[1]
            if curr < 0 or curr > capacity:
                return False

        return True


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
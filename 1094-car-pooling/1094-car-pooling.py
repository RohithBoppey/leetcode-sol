class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        dp = [0]*1001
        n = 0

        for i in trips: 
            dp[i[1]] += i[0]
            dp[i[2]] += -i[0]
            n = max(i[2], n)

        curr = 0
        for i in range(n + 1): 
            curr += dp[i]
            if curr < 0 or curr > capacity:
                return False

        # print(dp)
        return curr >= 0

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
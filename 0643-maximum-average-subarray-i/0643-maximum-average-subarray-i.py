class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n, i, j, mx = len(nums), 0, 0, -math.inf
        sm = 0

        while j < n:
            sm += nums[j]
            if j - i + 1 >= k:
                #  size met, only then do this 
                # find avg
                avg = sm / k
                mx = max(mx, avg)

                # move the i to the next step
                sm -= nums[i]
                i += 1

            j += 1
        
        return mx

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
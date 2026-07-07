class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n, i, j = len(nums), 0, 0
        mp = {}
        sm, mx = 0, 0

        while j < n: 
            if mp.get(nums[j]) == None: 
                mp[nums[j]] = 0
            
            mp[nums[j]] += 1
            sm += nums[j]

            # keep removing elements until condition met 
            while len(mp) != j - i + 1: 
                mp[nums[i]] -= 1
                sm -= nums[i]
                if mp[nums[i]] == 0:
                    mp.pop(nums[i])
                i += 1
            
            mx = max(sm, mx)
            j += 1
                
        return mx
        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
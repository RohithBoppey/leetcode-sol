class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        n = len(nums)
        max_val = max(nums)
        cnt = [0] * (max_val + len(nums) + 1)

        for i in nums:
            cnt[i] += 1

        steps = 0

        n = len(cnt)
        for i in range(n): 
            c = cnt[i]
            if c > 1: 
                # should find duplicates
                dup = c - 1
                steps += dup 

                # now move that many on to the next one
                cnt[i + 1] += dup

        return steps
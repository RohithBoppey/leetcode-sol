class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = [0]*(20**5 + 1)

        for i in nums:
            cnt[i] += 1

        steps = 0

        # can iterate on cnt array
        for i in range(len(cnt)): 
            c = cnt[i]
            dup = 0
            if c > 1: 
                dup = c - 1
                # duplicates needs to be incremented/subtracted
                steps += dup 
                
                # now that many dups move to the next step
                if i + 1 < len(cnt): 
                    cnt[i + 1] += dup

        return steps

Dump it on the next step: 

```py
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
```

Dry run: 
```
[1,2,2,3,3,3,4]

1 - 1
2 - 2
3 - 3
4 - 1

s = 0 + 1 = 1
1-1
2-1
3-4
4-1

s = 1 + 3 = 4
3 - 1
4 - 4

s = 4 + 3 = 7
4 - 1
5 - 3

s = 7 + 2 = 9
5 - 1
6 - 2

s = 9 + 1 = 10
6 - 1
7 - 1

ans = 10
```

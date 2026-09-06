- keep track for first index and last index - first half sum and second half sum and mimic every notation 
```py
class Solution:
    def countGoodRotations(self, nums: list[int]) -> int:
        n = len(nums)
        f,s = 0,0
        for i in range(n // 2): 
            f += nums[i]
            s += nums[(n // 2) + i]

        ans = 0
        fi, li = (n // 2) - 1, n - 1
        for i in range(n): 
            # print(f, s, fi, li)
            if f > s: 
                ans += 1
            
            # rotate 
            f += nums[li] - nums[fi]
            s += nums[fi] - nums[li]

            fi = (fi - 1) % n
            li = (li - 1) % n

        return ans
```

- sliding window, only think about first half and keep adding the first half index and second half index for n-1 times

```py
class Solution:
    def countGoodRotations(self, nums: list[int]) -> int:
        n = len(nums)

        sm = sum(nums)
        rn = 0
        i,j = 0,0 

        for i in range(n // 2):
            rn += nums[i]
            j += 1

        ans = 0
        i = 0
        c = n - 1
        
        while c >= 0: 
            # print(rn)
            if rn > sm - rn: 
                ans += 1

            rn += nums[j % n] - nums[i % n]
            j += 1
            i += 1
            c -= 1

        return ans
```

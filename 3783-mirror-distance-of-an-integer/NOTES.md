If the reverse function using list conversion
```py
def reverse_int(n):
    rev = str(n)[::-1]
    # 12000 -> 00012 --> 12
    rev = rev.lstrip()
    return int(rev)

class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n - reverse_int(n))
```

- using num logic
```py
def reverse_int(n):
    # using math
    ans = 0
    while(n > 0):
        rem = n % 10
        ans = (ans * 10) + rem
        n = n // 10
    return ans

```

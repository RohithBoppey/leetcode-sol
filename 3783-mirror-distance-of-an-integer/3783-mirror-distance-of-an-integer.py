def reverse_int(n):
    rev = str(n)[::-1]
    # 12000 -> 00012 --> 12
    rev = rev.lstrip()
    return int(rev)

class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n - reverse_int(n))
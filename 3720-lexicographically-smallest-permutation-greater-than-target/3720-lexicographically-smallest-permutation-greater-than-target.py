class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = Counter(s)

        # longest prefix of target buildable from s
        p = 0
        while p < n and cnt[target[p]] > 0:
            cnt[target[p]] -= 1
            p += 1

        # divergence point can't be n; release the last prefix char if we consumed all
        if p == n:
            cnt[target[n - 1]] += 1
        i = min(p, n - 1)

        while i >= 0:
            # smallest remaining letter strictly greater than target[i]
            for o in range(ord(target[i]) + 1, ord('z') + 1):
                ch = chr(o)
                if cnt[ch] > 0:
                    cnt[ch] -= 1
                    tail = []
                    for t in range(ord('a'), ord('z') + 1):
                        tail.append(chr(t) * cnt[chr(t)])
                    return target[:i] + ch + ''.join(tail)
            # back off one position, releasing that char into the pool
            i -= 1
            if i >= 0:
                cnt[target[i]] += 1

        return ""
        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
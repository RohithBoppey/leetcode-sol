class Solution:
    def smallestPalindrome(self, s: str) -> str:
        cnt = [0]*26
        for ch in s: 
            ind = ord(ch) - 97
            cnt[ind] += 1
        
        # print(cnt)

        n = len(s)
        ans = [""]*n
        first, last, mid = 0, n - 1, n // 2
        
        # for each letter, either add directly if odd or else from the back and front if even
        for i in range(26): 
            c = cnt[i]
            ch = chr(i + 97)

            for _ in range(c // 2): 
                # put in left and right 
                ans[first] = ch
                ans[last] = ch
                first += 1
                last -= 1

            # left over in center
            if c % 2 == 1:
                ans[mid] = ch

        return "".join(ans)

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
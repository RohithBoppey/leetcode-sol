def word_count(wc, word):
    c = 0       
    start, n = 0, len(word)

    while(1):
        ch = word[start]
        ind = ord(ch) - 97
        wc[ind] -= 1
        if wc[ind] < 0:
            # reached limit
            return c

        start = (start + 1) % n
        if start == 0:
            c += 1 

    return c

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        ac = [0]*26

        for ch in text:
            ind = ord(ch) - 97
            ac[ind] += 1
        
        # traverse balloon chars
        ans = word_count(ac, 'balloon')

        return ans


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
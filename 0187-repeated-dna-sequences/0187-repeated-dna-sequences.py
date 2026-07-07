class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        # key is 10 letter sequence 
        n, i, j = len(s), 0, 0
        mp = {}
        st = ''
        ans = []

        while j < n: 
            st += s[j]

            if j - i + 1 >= 10:
                # size met
                if mp.get(st) == None: 
                    mp[st] = 0
                mp[st] += 1

                # remove the ith letter
                st = st[1:]
                i += 1
            j += 1

        for k,v in mp.items(): 
            if v > 1:
                ans.append(k)

        return ans 

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
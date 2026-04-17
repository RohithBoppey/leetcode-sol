class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        # append list
        n = len(code)
        code = code + code + code
        ans = []

        for i in range(n, 2*n): 
            sm = 0
            sub = []
            if k < 0:
                # last k numbers
                sub = code[i + k: i]
                sm = sum(sub)
            elif k > 0: 
                sub = code[i + 1: i + k + 1]
                sm = sum(sub)
            else:
                # k == 0
                sm = 0
            ans.append(sm)
            # print(sub)

        return ans
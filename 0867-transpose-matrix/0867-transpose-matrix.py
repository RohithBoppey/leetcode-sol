class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        # with m*n -> inplace is not possible
        m, n = len(matrix), len(matrix[0])
        res = [[0]*m for _ in range(n)]
        print(res)

        for i in range(0, m):
            for j in range(0, n):
                res[j][i] = matrix[i][j]

        return res
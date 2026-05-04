2 steps: 
- transpose the image
- reverse each row ​

```py
def transpose(matrix: List[List[int]]) -> List[List[int]]:
        # in place
        n = len(matrix)

        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        
        # in place only, first transpose and then reverse each row 
        transpose(matrix)

        # now rotate each 
        for row in matrix: 
            row[:] = row[::-1]
        
        
```

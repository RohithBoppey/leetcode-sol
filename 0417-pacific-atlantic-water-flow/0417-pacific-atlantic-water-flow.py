drs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def dfs(vis, h, i, j): 
    if vis[i][j] == 1:
        return

    vis[i][j] = 1
    # each direction
    for d in drs: 
        nr, nc = i + d[0], j + d[1]
        # check if valid 
        if (nr >= 0 and nr < rows and nc >= 0 and nc < cols):
            # valid
            if h[nr][nc] >= h[i][j] and vis[nr][nc] == 0: 
                dfs(vis, h, nr, nc)


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # boundaries to inside increasing dfs
        global rows, cols
        rows, cols = len(heights), len(heights[0])
        
        # visited
        pcf = [[0]*cols for _ in range(rows)]
        atl = [[0]*cols for _ in range(rows)]

        # pcf = row 0
        for i in range(cols): 
            if pcf[0][i] == 0: 
                dfs(pcf, heights, 0, i)
        # pcf = col 0
        for i in range(rows):
            if pcf[i][0] == 0: 
                dfs(pcf, heights, i, 0)

        # atl = col n - 1
        for i in range(rows): 
            if atl[i][cols - 1] == 0: 
                dfs(atl, heights, i, cols - 1)
        
        # atl = row n - 1
        for i in range(cols):
            if atl[rows - 1][i] == 0: 
                dfs(atl, heights, rows - 1, i)

        # print(pcf)
        # print(atl)

        ans = []
        for i in range(rows):
            for j in range(cols):
                if atl[i][j] == 1 and pcf[i][j] == 1:
                    ans.append([i,j])

        return ans




# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
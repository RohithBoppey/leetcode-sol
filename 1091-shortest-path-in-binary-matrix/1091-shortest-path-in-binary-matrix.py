dirs = [(1,0), (-1,0), (1,1), (-1,1), (1,-1), (0,1), (0,-1), (-1,-1)]

class Solution:
    def shortestPathBinaryMatrix(self, grid: list[list[int]]) -> int:
        q = deque([])
        vis = {}
        n = len(grid)
        mx = -1

        if grid[0][0] != 0:
            return mx
        
        vis[(0,0)] = 1
        
        q.append((0,0,1))
        
        while len(q) != 0:
            f = q[0]
            # print(f)
            q.popleft()
            (r,c, co) = f

            if r == n - 1 and c == n - 1:
                return co

            for (dr, dc) in dirs:
                nr = r + dr
                nc = c + dc

                if nr >= 0 and nr < n and nc >= 0 and nc < n:
                    # continue
                    if vis.get((nr, nc)) == None and grid[nr][nc] == 0:
                        vis[(nr,nc)] = 1
                        q.append((nr, nc, co+1))

        return -1

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
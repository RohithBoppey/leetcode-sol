def solve(i, n, vis, conn): 
    vis[i] = 1 
    # push all neighbours 
    for j in range(n): 
        if i != j and conn[i][j] == 1 and vis[j] == 0: 
            # connection there, and the children is not visited
            solve(j, n, vis, conn)


class Solution:
    def findCircleNum(self, conn: List[List[int]]) -> int:
        # do dfs
        ans, n = 0, len(conn)
        vis = [0] * n

        for i in range(n):
            if vis[i] == 0: 
                # not visited
                solve(i, n, vis, conn)
                ans += 1

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
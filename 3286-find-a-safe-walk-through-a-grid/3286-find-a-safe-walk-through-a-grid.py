from collections import deque

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])

        # if the starting cell is unsafe, health decreases immediately
        start_health = health - grid[0][0]

        # health should always remain positive
        if start_health < 1:
            return False

        # stores the maximum health left when reaching each cell
        # initialize with -1 meaning the cell has not been reached yet
        vis = []

        for _ in range(m):
            arr = []
            for _ in range(n):
                arr.append(-1)
            vis.append(arr)

        # queue stores: (row, col, remaining_health)
        q = deque([(0, 0, start_health)])
        vis[0][0] = start_health

        # traverse using BFS and explore all possible healthy routes
        while len(q) != 0:
            r, c, curr_health = q.popleft()

            # if we've reached the destination with health >= 1
            if r == m - 1 and c == n - 1:
                return True

            # now add neighbours
            for d in dirs:
                nr, nc = r + d[0], c + d[1]

                # check if the neighbour is valid or not
                if (nr >= 0 and nr < m) and (nc >= 0 and nc < n):

                    # entering an unsafe cell costs 1 health
                    new_health = curr_health - grid[nr][nc]

                    # cannot move if health becomes zero or negative
                    if new_health < 1:
                        continue

                    # visit this cell only if we are reaching it
                    # with more health than before
                    if new_health > vis[nr][nc]:
                        vis[nr][nc] = new_health
                        q.append((nr, nc, new_health))

        return False

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
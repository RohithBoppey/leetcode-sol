class DSU: 
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1 for _ in range(n)]

    def find(self, x): 
        while (self.parent[x] != x):
            x = self.parent[x]
        return x

    def connected(self, x, y):
        return self.find(x) == self.find(y)

    def union(self, x, y):
        a = self.find(x)
        b = self.find(y)

        if a == b: 
            return 

        if self.size[a] < self.size[b]: 
            # merge a into b
            self.parent[a] = b
            self.size[b] += self.size[a]
        else:
            self.parent[b] = a
            self.size[a] += self.size[b]


class Solution:
    def findCircleNum(self, conn: List[List[int]]) -> int:
        # solving using DSU
        
        # # test
        # dsu = DSU(5)
        # dsu.union(0,1)
        # dsu.union(1,2)
        # print(dsu.connected(0,2))
        # print(dsu.connected(0,3))

        n = len(conn)
        dsu = DSU(n)

        for i in range(n):
            for j in range(n): 
                if i != j and conn[i][j] == 1: 
                    # unify into a component
                    dsu.union(i, j)

        # now to update the parent linearly
        ans = 0
        for i in range(n):
            x = dsu.find(i)
            ans += 1 if x == i else 0

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
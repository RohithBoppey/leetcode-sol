class DSU: 
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.size = [1 for i in range(n + 1)] 

    def find(self, x): 
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y): 
        a, b = self.find(x), self.find(y)
        if a == b:
            return
        if self.size[a] > self.size[b]:
            self.parent[b] = a 
            self.size[a] += self.size[b]
        else:
            self.parent[a] = b
            self.size[b] += self.size[a]

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        dsu = DSU(n)

        for [a,b] in edges: 
            if dsu.find(a) == dsu.find(b):
                return [a,b]
            dsu.union(a, b)
        
        return [0, 0]

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
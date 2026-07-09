class DSU: 
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1 for _ in range(n)]

    def find(self, x): 
        # updated algo
        if self.parent[x] != x: 
            # should update
            self.parent[x] = self.find(self.parent[x])
        
        return self.parent[x]

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
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:

        dsu = DSU(n)

        arr = [(nums[i], i) for i in range(n)]
        # sort only side by side values 
        arr.sort(key = lambda x: (x[0], x[1]))

        # print(arr)
        for i in range(1, n): 
            if abs(arr[i][0] - arr[i - 1][0]) <= maxDiff: 
                # allowed
                dsu.union(arr[i][1], arr[i - 1][1])
        
        ans = []
        for q in queries: 
            if dsu.find(q[0]) == dsu.find(q[1]):
                ans.append(True)
            else:
                ans.append(False)

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
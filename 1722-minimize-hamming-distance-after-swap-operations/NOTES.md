
The idea is if we use DSU to join the indices, that gives us groups like this: {0,1,2,3} {4,5}
- that means in those indices, we can make the swaps as we want
- so in a particular group, we can take count of elements from source and target, to find out how many mismatches are there, then that would be the count

```py
class DSU():
    def __init__(self, n):
        # only on indexes
        self.n = n
        self.parent = [i for i in range(self.n)]
        
        self.size = [1]*self.n

    def find(self, x):
        # using path compression
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        
        return self.parent[x]

    def union(self, x, y):
        # find smaller tree - merge in big one
        ap = self.find(x)
        bp = self.find(y)

        if ap == bp:
            # already union-ed
            return True

        asz = self.size[ap]
        bsz = self.size[bp]

        if asz < bsz: 
            # merge a with b
            self.parent[ap] = bp
            self.size[bp] += asz
        else:
            self.parent[bp] = ap
            self.size[ap] += bsz

    def components(self):
        comp = {}
        
        for i in range(self.n):
            root = self.find(i)
            
            if root not in comp:
                comp[root] = []
            
            comp[root].append(i)
        
        return comp



class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        
        n = len(source)
        dsu = DSU(n)

        # connect all nodes
        for swap in allowedSwaps: 
            dsu.union(swap[0], swap[1])

        # print(dsu.parent)
        comps = dsu.components()
        # print(comps)

        # for each component, the number of components in it should match 
        ans = 0
        for indices in comps.values(): 
            count = {}

            for i in indices: 
                # now count source elemnts count
                count[source[i]] = count.get(source[i], 0) + 1
            
            # now for the same indices, remove the target count to find mismatches
            for i in indices:
                if count.get(target[i], 0) > 0:
                    count[target[i]] -= 1
                else:
                    # this element is not present, mismatch
                    ans += 1

        
        return ans 


```

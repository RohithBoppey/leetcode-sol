[Source](https://www.youtube.com/watch?v=0jNmHPfA_yE&list=PLDV1Zeh2NRsBI1C-mR6ZhHTyfoEJWlxvq&index=3)  
The idea is to club multiple elements into one or multiple disjoint sets  
  
#### Implementation

Bare metal implementation (no path compression, find takes - O(N) time
```py
class DSU:
    def __init__(self, n):
        # parent[i] = parent of node i - initially the same
        self.parent = [i for i in range(n)]
        
        # to answer the size of the tree present so far whose size is n
        self.size = [1] * n

    def find(self, x):
        # keep iterating the array until you find whose index = value and return parent
        while (self.parent[x] != x):
            x = self.parent[x]
        return x

    def union(self, x, y):
        # merge the smaller parent, with the bigger parent
        a = self.find(x)
        b = self.find(y)
        
        # if already connected, skip
        if a == b:
            return
        
        asz = self.size[a]
        bsz = self.size[b]
        
        if self.size[a] < self.size[b]:
            # merge a inside b --> a's parent should be b
            # now b size should increase
            self.parent[a] = b
            self.size[b] += asz
            
        else:
            self.parent[b] = a
            self.size[a] += bsz

    def connected(self, x, y):
        return self.find(x) == self.find(y)
    

dsu = DSU(5)

dsu.union(0, 1)
dsu.union(1, 2)

print(dsu.connected(0, 2))  # True
print(dsu.connected(0, 3))  # False
```
  
With path compression (essentially means all the ): 
```py
class DSU:
    def __init__(self, n):
        # parent[i] = parent of node i - initially the same
        self.parent = [i for i in range(n)]
        
        # to answer the size of the tree present so far whose size is n
        self.size = [1] * n

    def find(self, x):
        # keep iterating the array until you find whose index = value and return parent
        # in path compression, once unioned, all the children point to the child directly
        if self.parent[x] != x: 
            # then we can update the parent of it to point to it's parent as well 
            self.parent[x] = self.find(self.parent[x])
        
        # at this point, all the branches are flattened
        return self.parent[x]

    def union(self, x, y):
        # merge the smaller parent, with the bigger parent
        a = self.find(x)
        b = self.find(y)
        
        # if already connected, skip
        if a == b:
            return
        
        asz = self.size[a]
        bsz = self.size[b]
        
        if self.size[a] < self.size[b]:
            # merge a inside b --> a's parent should be b
            # now b size should increase
            self.parent[a] = b
            self.size[b] += asz
            
        else:
            self.parent[b] = a
            self.size[a] += bsz

    def connected(self, x, y):
        return self.find(x) == self.find(y)
    

dsu = DSU(5)

dsu.union(0, 1)
dsu.union(1, 2)

print(dsu.connected(0, 2))  # True
print(dsu.connected(0, 3))  # False
```

    
P1: [Minimum hamming distance](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/submissions/1984974456/?envType=daily-question&envId=2026-04-21)


- Simple solution but with using extra space
```py
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        new = []
        
        left = []
        right = []
        xc = 0

        for i in nums: 
            if i < pivot:
                left.append(i)
            elif i > pivot:
                right.append(i)
            else:
                xc += 1

        while len(left) > 0:
            x = left.pop(0)
            new.append(x)

        while xc > 0:
            new.append(pivot)
            xc -= 1
            
        while len(right) > 0:
            x = right.pop(0)
            new.append(x)

        return new
```

- I think the key lies in not using extra space

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

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
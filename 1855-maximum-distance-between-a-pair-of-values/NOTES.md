Binary search on the right array with the left index possible - always give a min index, which is the least max that you can take difference for

```py
def bs(nums, val, left = 0):
    # right most if equal, else give an index, like nums2[ind] <= val
    n = len(nums)
    start, end = left, n - 1
    ans = -1

    while start <= end:
        mid = start + (end - start) // 2
        if nums[mid] < val: 
            # move window to the left
            end = mid - 1
        else:
            # nums[mid] >= start
            # shift window to the right
            # but this number is the start of max value possible 
            ans = mid
            start = mid + 1
            
    return ans


class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        ans = 0
        for i in range(0, n):
            ind = bs(nums2, nums1[i], i)
            if ind != - 1:
                # first max value found for this pair
                ans = max(ans, ind - i)

        return ans
```

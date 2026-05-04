class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n

        # now reverse left, right, full
        
        # left -> [0, n - k - 1] elements
        nums[:n-k] = nums[:n-k][::-1]
        print(nums)
        # right -> [n - k, n - 1] elements
        nums[n-k:] = nums[n-k:][::-1]
        print(nums)
        # full reverse
        nums[:] = nums[::-1]
        


        
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # start from behind to find the breaking point or current exhaustion point 
        n = len(nums)
        i = n - 1

        while i > 0 and nums[i - 1] >= nums[i]: 
            i -= 1

        pos = i - 1

        if pos == -1:
            nums.reverse()
        else:
            # find number slightly more than the current
            ind = n - 1
            for i in range(n - 1, pos, -1): 
                if nums[i] > nums[pos]:
                    ind = i
                    break

            # worst case i pointing to pos + 1 = start of right side 
            nums[pos], nums[ind] = nums[ind], nums[pos]
            nums[pos + 1:] = reversed(nums[pos + 1:])
        
        return nums

        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
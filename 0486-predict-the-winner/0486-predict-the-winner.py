class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)

        def solve(left, right):
            if left == right: 
                return nums[left]
            
            # left and right gain
            lg, rg = nums[left] - solve(left + 1, right), nums[right] - solve(left, right - 1)

            return max(lg, rg)
            
        # if final player one gain is positive, he wins
        return solve(0, n - 1) >= 0
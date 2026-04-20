class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        # min heap
        heapq.heapify(nums)
        mod = 10**9 + 7

        for i in range(k): 
            mn = heapq.heappop(nums)
            heapq.heappush(nums, mn + 1)
        
        # now mul all
        ans = 1
        for x in nums: 
            ans = (ans * x) % mod
        return ans
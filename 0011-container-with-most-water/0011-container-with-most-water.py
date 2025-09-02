class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        h = len(height) - 1

        mx = 0

        # take 2 pointers -> iterate and find the container with most water
        while(l < h):
            width = h - l
            curr_height = min(height[l], height[h])
            mx = max(mx, width * curr_height)

            # now reduce based on the min value
            if height[l] < height[h]:
                # that means in the next iteration, I might find a better equal height
                l += 1
            else:
                h -= 1

        return mx
class Solution:
    def countGroups(self, position: list[int], speed: list[int], distance: int) -> int:
        n = len(speed)
        c = 1

        for i in range(n - 1, 0, -1):
            if speed[i] < speed[i-1] or position[i] - position[i-1] <= distance:
                # merge it
                speed[i-1] = speed[i]
            else:
                c += 1

        return c


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
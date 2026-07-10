class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1

        start = 0
        tank = 0

        for i in range(len(gas)):
            # Fuel after reaching the next station
            tank += gas[i] - cost[i]

            # Can't reach the next station from the current start
            if tank < 0:
                # None of the stations from start to i can be the answer
                start = i + 1
                # Start fresh from the next station
                tank = 0

        return start

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
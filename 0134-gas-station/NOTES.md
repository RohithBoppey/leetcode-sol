- if starting from position A and failed at position B, that means any start position anywhere between A and B cannot be valid due to net sum negative, hence start from B + 1, tank = 0

```py
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
```

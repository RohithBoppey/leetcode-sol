What is Dynamic Programming? -> Enhanced version of Recursion -> So understanding all approaches of a problem: Recursive, Top Down, Bottom Up, Memoized version.
![image](https://github.com/user-attachments/assets/b1ca11dc-b2d0-4ec2-aabe-9d2465828348)

How to identify DP/Recursion? All ways can be applicable for Recursion & DP:
1. Some kind of **choice** is required -> can take, can not take.
2. Along with 1. Find the most profit, loss, etc??
3. Some kind of overlap is exisiting while breaking the big problem into subproblems.

**Find the Recursive solution first, and then move to the above solutions like Top Down, Bottom Up approaches**

Various Kinds of problems: 
![image](https://github.com/user-attachments/assets/5fbaa781-218e-4639-8649-ae2e60b7ba37)

### Knapsack problem
---
![image](https://github.com/user-attachments/assets/44392357-4eee-49cc-ae9d-d6501396374f)
- Fractional Knapsack comes under `Greedy Problem`. If the capacity is not filled, then if breaking the item into fractions and take the fraction of cost to the profit. 
- Knapsack is the classic **BAG PROBLEM** -> given the weight array and the value array for few items -> so they will give us 2 arrays
- Input is given as: capacity/weight W that the bag can contain
- Problem is to put x items in the bag such that the value inside the bag is maximum and sum(items) < capacity/W
- 0-1 knapsack: We can only put one element of the array inside the bag until the conditions are met. Post that is added, move to the next element in the array.
- Unbounded knapsack: 0-1 knapsack + unlimited instances of the same item can be placed inside the bag. Use the same arr[i] element many number of times until the conditions are met.

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

Problem Statement: [GFG Problem Statement](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

#### Solving Knapsack problem using Recursion
![image](https://github.com/user-attachments/assets/2c781b86-6fc0-4557-8c6f-2364a79d3f35)      
- The reason we took from the last is that, we always want to narrow down the input -> and order doesn't matter that much in here, because either way, we are checking all entries.
```c++
int solve(vector<int>& wt, vector<int>& val, int C, int n){
      // base condition: either there are no elements to put in the bag or 
      // else there is no capacity in the bag to put in a new element
      
      // considering n - 1 is the current, can do from the start, but put i as the start 
      
      if(n == 0 || C == 0){
          // for this configuration only, the max profit that we can generate is 0
          return 0;
      }
      
      // we can take or not take
      int take = val[n - 1] + solve(wt, val, C - wt[n - 1], n - 1);
      int not_take = solve(wt, val, C, n - 1);
      
      
      // when can I take, and when should I skip
      if(wt[n - 1] <= C){
          // I can take or else skip, so for this configuration, give me the best profit and I will return that
          return max(take, not_take);
      }
      
      // I have no other way, but to not take this input, so directly return the max profit that I can obtain by not taking
      return not_take;
      
  }
  
  int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
      int n = wt.size();
      return solve(wt, val, capacity, n);
  }
```
Using start logic, that we are familiar with: 
```c++
// Function to return max value that can be put in knapsack of capacity.
int solve(vector<int>& wt, vector<int>& val, int C, int n, int start){

  // base condition: either there are no elements to put in the bag or 
  // else there is no capacity in the bag to put in a new element
  
  // considering n - 1 is the current, can do from the start, but put i as the start 
  
  if(start >= n || C == 0){
      // for this configuration only, the max profit that we can generate is 0
      return 0;
  }
  
  // we can take or not take
  int take = val[start] + solve(wt, val, C - wt[start], n, start + 1);
  int not_take = solve(wt, val, C, n, start + 1);
  
  
  // when can I take, and when should I skip
  if(wt[start] <= C){
      // I can take or else skip, so for this configuration, give me the best profit and I will return that
      return max(take, not_take);
  }
  
  // I have no other way, but to not take this input, so directly return the max profit that I can obtain by not taking
  return not_take;  
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
  int n = wt.size();
  int start = 0;
  return solve(wt, val, capacity, n, start);
}
```
- This will definitely fail and give you TLE because this is not the best optimized solution, there are repetitions that we can solve.

#### Solving using memoization
- Alternative to top down appraoch (matrix building from top to bottom) -> memoization & easy appraoch
- Always try to approach the problem using recursion -> then to memoization rather than using top down approach
- Adding dp[][] whereever recursion is being used & in return statements.
```c++

// Function to return max value that can be put in knapsack of capacity.
int solve(vector<int>& wt, vector<int>& val, int C, int n, vector<vector<int>>& dp){
  // base condition: either there are no elements to put in the bag or 
  // else there is no capacity in the bag to put in a new element
  
  // considering n - 1 is the current, can do from the start, but put i as the start 
  
  if(n == 0 || C == 0){
      // for this configuration only, the max profit that we can generate is 0
      return 0;
  }
  
  // if already visited
  if(dp[n][C] != -1){
      return dp[n][C];
  }
  
  // Option 1: Do not take the current item
  int not_take = solve(wt, val, C, n - 1, dp);

  // Option 2: Take the current item (only if its weight is <= capacity)
  int take = 0;
  if (wt[n - 1] <= C) {
      take = val[n - 1] + solve(wt, val, C - wt[n - 1], n - 1, dp);
  }

  // Store the maximum of the two options in dp
  dp[n][C] = max(take, not_take);
  return dp[n][C];
          
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
  int n = wt.size();
  
  vector<vector<int>> dp(1001, vector<int>(1001, -1));
  return solve(wt, val, capacity, n, dp);
}
```

#### Solving using Top-Down Approach
- The initialization for top down approach is different: initialize first row and column and build the other logic based on that
  ![image](https://github.com/user-attachments/assets/cb468849-2323-4dfd-84f2-a7690b8c01f2)
- In the top down, we do not have recursive call at all, but rather the for loop after building the base conditions (first row and first column)
```
Input Explanation
c 4
val 1 2 3
wt 4 5 1
----------
dp[n + 1][c + 1] = dp[4][5]

0 0 0 0 0
0 0 0 0 1
0 0 0 0 1
0 3 3 3 3

```
- `Always use either memoization or top down approach - stick with one approach`
```c++
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int c, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
        
        // initialisation 
        // if n == 0 or else c == 0, max profit we can obtain is 0
        
        for(int i = 0; i <= c; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        
        // processing
        int take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= c; j++){
                
                // for each step, we can take or not take
                // take only if the current weight is 0
                take = (wt[i - 1] <= j) ? (val[i - 1] + dp[i - 1][j - wt[i - 1]]) : 0;
                notTake = dp[i - 1][j];
                
                dp[i][j] = max(take, notTake);
            }
        }
        
        
        return dp[n][c];
    }
};

```
![WhatsApp Image 2025-01-01 at 21 27 09_ea25dbaf](https://github.com/user-attachments/assets/a3a2bedb-7efd-4c89-883a-fb8bbd861af8)
![WhatsApp Image 2025-01-01 at 21 27 09_bd8ebc6c](https://github.com/user-attachments/assets/861f80d7-06d6-4c1f-af47-ff31daf2162a)

## Subset Sum Problem
[GFG Link](https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
[Leetcode Link](https://leetcode.com/problems/target-sum/)
Base case: 
- if my target == 0, that means the subset I took is a valid subset, can return true
- if my start position > n, that means we cannot do anything, so return false

```c++
class Solution {
  public:
  
    int n;

    bool solve(vector<int>& arr, int target, int start, vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }
        
        if(start >= n){
            return false;
        }
        
        if(dp[start][target] != -1){
            return dp[start][target];
        }
        
        // either take or not take
        // take only when possible
        int take, notTake;
        take = (arr[start] <= target) ? solve(arr, target - arr[start], start + 1, dp) : false;
        notTake = solve(arr, target, start + 1, dp);
        
        return dp[start][target] = take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        n = arr.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        return solve(arr, target, 0, dp);
    }
};

```
Using the top-down approach: 
```c++
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
        
        // first column ->> when target = 0, the subset can be constructed easily -> {}, so all rows of the first column contains true
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        // processing part
        int take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                
                // can take or not take
                // take only when the current element weight is less than target
                take = (arr[i - 1] <= j) ? dp[i - 1][j - arr[i - 1]] : false;
                notTake = dp[i - 1][j];
                
                dp[i][j] = take || notTake;
            }
        }
        
        return dp[n][target];
        
    }
};
```
      
## Equal Sum Partition Problem
[Problem Link](https://leetcode.com/problems/partition-equal-subset-sum/submissions/1494274553/)       
Explanation: [Link](https://github.com/RohithBoppey/leetcode-sol/blob/master/0416-partition-equal-subset-sum/0416-partition-equal-subset-sum.cpp)

## Partition into 2 subsets & find min difference between them
```c++
class Solution {

  public:
  
    int n;
  
    bool solve(vector<int>& nums, int start, int target, vector<vector<int>>& dp){
        if(dp[start][target] != -1){
            return dp[start][target];
        }

        if(start >= n){
            // cannot proceed further
            return (target == 0) ? true : false;
        }   

        // processing
        // can take or cannot take
        int take, notTake;

        // only take if my current val can fit in the bag
        take = (nums[start] <= target) ? solve(nums, start + 1, target - nums[start], dp) : false;
        notTake = solve(nums, start + 1, target, dp);

        return dp[start][target] = take || notTake; 
    }
  
    int minDifference(vector<int>& nums) {
        // Your code goes here
        
        n = nums.size();
        
        if(n == 1){
            // cannot split into 2 subsets, so return the ele
            return nums[0];
        }
        
        int sum = 0;
        for(int x: nums){
            sum += x;
        }

        // solve for only the half of the range
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        // now only solve for the S1 range -> 1 to range / 2
        int mn = INT_MAX;
        for(int i = 1; i <= target; i++){
            if(solve(nums, 0, i, dp)){
                // the subset is present
                mn = min(mn, sum - 2*i);
            }
        }

        return mn;
        
    }
};

```

Top Down Solution:
```c++
class Solution {
  public:
  
    int n;
    
    void print2(vector<vector<int>>& dp){
        for(auto &x: dp){
            for(auto &y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }
    
    
    int solve(vector<int>& arr, int target, vector<vector<int>>& dp){
        
        // initialisation        
        // n == 0
        for(int i = 0; i <= target; i++){
            dp[0][i] = 0;
        }
        
        // target sum = 0 -> 1 subset exists
        // for(int i = 0; i <= n; i++){
        //     dp[i][0] = 1;
        // }
       
        dp[0][0] = 1;
        
        // processing
        int take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
             // can take or not take
             // take only when the current element is less than the limit
                take = (arr[i - 1] <= j) ? dp[i - 1][j - arr[i - 1]] : 0;
                notTake = dp[i - 1][j];
                
                // such sum can exist in both the cases, so +
                dp[i][j] = take + notTake;
                
            }
        }
        
        // print2d(dp);
        
        return dp[n][target];
    }
  
  
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        
        // going with tabulation method
        n = arr.size();
        
        int sum = 0;
        
        for(auto &x: arr){
            sum += x;
        }
        
        int target = (sum + d) / 2;
        
        if((sum + d) % 2 == 1){
            // odd sum, cannot split into 2 sub arrays
            return 0;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        return solve(arr, target, dp);
    }
};
```
![WhatsApp Image 2025-01-03 at 22 42 27_24bf1453](https://github.com/user-attachments/assets/7e7d916a-e9eb-4eb2-b37c-e97f4a163b7b)



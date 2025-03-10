understanding all approaches of a problem: Recursive, Top Down, Bottom Up, Memoized version.
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
---
# **Unbounded Knapsack Problems: **
- The main difference is that in these kinds of problems, the elements can repeat and need not diminish, so the only difference is for moving into the subproblem. `dp[i][j = wt[i - 1]` is the condition, this will keep going until it is not possible.

## Classic Rod Cutting Problem
[GFG Link](https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

Top Down solution: 
```c++
class Solution {
  public:
    int n;
  
    void print2d(vector<vector<int>>& v){
        for(auto &x: v){
            for(auto y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }
  
    // 3 5 8 9 10 17 17 20
    // 1 5 8 9 10 17 17 20
    int cutRod(vector<int> &price) {
        // code here
        n = price.size();
        
        // dp[array_size + 1][rod_length + 1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // this array means the rod length -> weight of the object that is put in the knapsack
        vector<int> array(n + 1);
        for(int i = 0; i <= n; i++){
            array[i] = i + 1;
        }
        
        // when the rod length is 0, max profit obtained is 0
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        
        // when the array length is 0, there are no length wise costs at all, so profit obtained is 0
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }
        
        // processing
        int take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                
                // is there a condition? 
                // cut the rod and add the price only when the given element (rod length) <= the actual rod length given
                take = (array[i - 1] <= j) ? price[i - 1] + dp[i][j - array[i - 1]] : 0;
                notTake = dp[i - 1][j];
                
                dp[i][j] = max(take, notTake);
                
            }
        }
        
        // print2d(dp);
        
        return dp[n][n];
        
        
        
    }
};
```

Similar concept for the coin change concept: 
1. Min Number of coins
```c++
class Solution {
public:
    int n;

    void print2d(vector<vector<long>>& v){
        for(auto &x: v){
            for(auto y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        
        n = coins.size();

        vector<vector<long>> dp(n + 1, vector<long>(amount + 1, -1));

        // initialisation
        // slightly tricky

        // if we have no elements, it requires INF elements to match the coin amount
        for(int i = 0; i <= amount; i++){
            dp[0][i] = INT_MAX;
        }

        // if the sum required is 0, then no matter the size of the array is, we can always have 0 coins to match the sum
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }


        // processing
        long take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){

                // add the coin amount only if it is greater than the coin requirement
                // just the amount gets decreased now, but not the array size
                // since unbounded knapsack concept, can still divide using that certain element
                take = (coins[i - 1] <= j) ? (long)(1 + dp[i][j - coins[i - 1]]) : INT_MAX;
                notTake = dp[i - 1][j];

                dp[i][j] = min(take, notTake);

            }
        }

        // print2d(dp);

        return (dp[n][amount] >= INT_MAX) ? -1 : dp[n][amount];

    }
};
```
2. How many number of ways can we split the coins
```c++
class Solution {
public:

    int n;

    void print2d(vector<vector<long>>& v){
        for(auto &x: v){
            for(auto y: x){
                cout << y << " ";
            }
            cout << endl;
        }
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();

        vector<vector<long>> dp(n + 1, vector<long>(amount + 1, 0));

        // initialisation
 
        // if there are no elements, then no way to fill the sum, so fill with 0
        for(int i = 0; i <= amount; i++){
            dp[0][i] = 0;
        }


        // if required sum = 0, then there is only way to get that amount -> {}, so fill with 1
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        // processing
        int take, notTake;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){

                // take only when the value of the coin is less than the required limit
                take = (coins[i - 1] <= j) ? dp[i][j - coins[i - 1]] : 0;
                notTake = dp[i - 1][j];

                dp[i][j] = (long) take + notTake;

            }
        }

        // print2d(dp);

        return dp[n][amount];

    }
};
```
---
# Longest Common Subsequence Type problems: 
![image](https://github.com/user-attachments/assets/69377f66-79ed-49cd-b70d-94f8d9a99f44)

## Longest Common Subsequence

[Leetcode Link](https://leetcode.com/problems/longest-common-subsequence/submissions/1499832405/)

Recursive solution (Gives you TLE) ❌:
```c++
class Solution {
public:

    int solve(string& x, string& y, int l1, int l2){
        if(l1 == 0 || l2 == 0){
            // we cannot generate any common substring
            return 0;
        }

        // processing
        if(x[l1 - 1] ==  y[l2 - 1]){
            // if they are equal -> THEY MUST BE INCLUDED IN THE SUBARRAY
            return 1 + solve(x, y, l1 - 1, l2 - 1);
        }

        // else
        // now we can either remove one from that, or one from this
        int o1 = solve(x, y, l1 - 1, l2);
        int o2 = solve(x, y, l1, l2 - 1);

        // for the current configuration, give me the max found
        return max(o1, o2);

    }

    int longestCommonSubsequence(string text1, string text2) {
        // solving it recursively
        int l1 = text1.size();
        int l2 = text2.size();

        // starting from behind
        return solve(text1, text2, l1, l2);

    }
};
```

Recursive solution (Gives you TLE) - logic from the start, putting start = 0 ❌:
```c++
class Solution {
public:

    int solve(string& x, string& y, int l1, int l2, int start1, int start2){
        if(start1 >= l1 || start2 >= l2){
            // we cannot generate any common substring
            return 0;
        }

        // processing
        if(x[start1] ==  y[start2]){
            // if they are equal -> THEY MUST BE INCLUDED IN THE SUBARRAY
            return 1 + solve(x, y, l1, l2, start1 + 1, start2 + 1);
        }

        // else
        // now we can either remove one from that, or one from this
        int o1 = solve(x, y, l1, l2, start1 + 1, start2);
        int o2 = solve(x, y, l1, l2, start1, start2 + 1);

        // for the current configuration, give me the max found
        return max(o1, o2);

    }

    int longestCommonSubsequence(string text1, string text2) {
        // solving it recursively
        int l1 = text1.size();
        int l2 = text2.size();

        // starting from behind
        return solve(text1, text2, l1, l2, 0, 0);

    }
};
```

Recursion + memoization approach: 
```c++
class Solution {
public:

    int solve(string& x, string& y, int l1, int l2, int start1, int start2,
    vector<vector<int>>& dp){
        if(start1 >= l1 || start2 >= l2){
            // we cannot generate any common substring
            return dp[start1][start2] = 0;
        }

        // check if this subproblem is already seen or not
        if(dp[start1][start2] != -1){
            // already seen
            return dp[start1][start2];
        }

        // processing
        if(x[start1] ==  y[start2]){
            // if they are equal -> THEY MUST BE INCLUDED IN THE SUBARRAY
            return dp[start1][start2] = 1 + solve(x, y, l1, l2, start1 + 1, start2 + 1, dp);
        }

        // else
        // now we can either remove one from that, or one from this
        int o1 = solve(x, y, l1, l2, start1 + 1, start2, dp);
        int o2 = solve(x, y, l1, l2, start1, start2 + 1, dp);

        // for the current configuration, give me the max found
        return dp[start1][start2] = max(o1, o2);

    }

    int longestCommonSubsequence(string text1, string text2) {
        // solving it recursively
        int l1 = text1.size();
        int l2 = text2.size();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));

        // starting from behind
        return solve(text1, text2, l1, l2, 0, 0, dp);

    }
};
```

Top Down approach (Memoization): 
```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        
        // initialisation
        // if l1 == 0 or l2 == 0, the common subsequence length = 0
        // already done in the declaration part

        // processing
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){

                // check whether it is matching or not matching
                if(text1[i - 1] == text2[j - 1]){
                    // matching
                    // MUST INCLUDE - so remove those
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else{
                    // not matching
                    // can be either of 2 cases
                    int first, second;
                    first = dp[i - 1][j];
                    second = dp[i][j - 1];

                    dp[i][j] = max(first, second);
                }

            }   
        }

        return dp[l1][l2];
    }
};
```
## Longest Common Substring
[GFG Link](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
```c++
class Solution {
  public:
    int longestCommonSubstr(string& text1, string& text2) {
        // your code here
        int l1 = text1.size();
        int l2 = text2.size();
        
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        
        // initialisation
        // if l1 == 0 or l2 == 0, the common subsequence length = 0
        // already done in the declaration part

        // processing
        int mx = 0;
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){

                // check whether it is matching or not matching
                if(text1[i - 1] == text2[j - 1]){
                    // matching
                    // MUST INCLUDE - so remove those
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    mx = max(mx, dp[i][j]);
                }

                else{
                    // not matching
                    // can be either of 2 cases
                    dp[i][j] = 0;
                }

            }   
        }

        return mx;
    }
};

```

## Printing Longest common subsequence
![image](https://github.com/user-attachments/assets/ecc16520-725b-4000-bf1d-1838bd172d09)            
The idea is to fill the LCS array with lengths, and if we can see that i and j are equal -> that means we MUST have taken that account into consideration.
Else -> we must have come to that point from a maximum length.
```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        
        // initialisation
        // if l1 == 0 or l2 == 0, the common subsequence length = 0
        // already done in the declaration part

        // processing
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){

                // check whether it is matching or not matching
                if(text1[i - 1] == text2[j - 1]){
                    // matching
                    // MUST INCLUDE - so remove those
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else{
                    // not matching
                    // can be either of 2 cases
                    int first, second;
                    first = dp[i - 1][j];
                    second = dp[i][j - 1];

                    dp[i][j] = max(first, second);
                }

            }   
        }

        // printing the LCS part
        int i = l1, j = l2;
        string res = "";
        while(i > 0 && j > 0){
            if(text1[i - 1] == text2[j - 1]){
                // we are taking that element
                res += text1[i - 1];
                i--;
                j--;
            } else{
                // one of them is greater, move in that direction
                if(dp[i][j - 1] > dp[i - 1][j]){
                    j--;
                }else{
                    i--;
                }
            }
        }

        reverse(res.begin(), res.end());
        
        cout << res << endl;

        return dp[l1][l2];
    }
};
```
## Printing Shortest common supersequence
- Slight modification from printing the subsequence
- When matched, we need just once right? Else, we need to add the missing part from left, as well as right
```c++
class Solution {
public:

    string solve(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        
        // initialisation
        // if l1 == 0 or l2 == 0, the common subsequence length = 0
        // already done in the declaration part

        // processing
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){

                // check whether it is matching or not matching
                if(text1[i - 1] == text2[j - 1]){
                    // matching
                    // MUST INCLUDE - so remove those
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else{
                    // not matching
                    // can be either of 2 cases
                    int first, second;
                    first = dp[i - 1][j];
                    second = dp[i][j - 1];

                    dp[i][j] = max(first, second);
                }

            }   
        }

        // printing the LCS part
        int i = l1, j = l2;
        string res = "";
        while(i > 0 && j > 0){
            if(text1[i - 1] == text2[j - 1]){
                // we are taking that element
                res += text1[i - 1];
                i--;
                j--;
            } else{
                // one of them is greater, move in that direction
                if(dp[i][j - 1] > dp[i - 1][j]){
                    res += text2[j - 1];
                    j--;
                }else{
                    res += text1[i - 1];
                    i--;
                }
            }
        }

        while(i>0){
            res += text1[i-1];
            i--;
        }
        while(j>0){
            res += text2[j-1];
            j--;
        }

        reverse(res.begin(), res.end());

        return res;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        
        string common = solve(str1, str2);
        if(common.length() == 0){
            return str1 + str2;
        }

       return common;

    }

};
```
## Longest Repeating Subsequence 
[GFG Link](https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

So in the same string, you need to find the length of the biggest subsequence which is appearing twice in the array

```c++
class Solution {
  public:
  
    int l;
  
    // solve using top down appraoch
  
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        
        l = s.size();
        
        vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));
        
        
        for(int i = 1; i <= l; i++){
            for(int j = 1; j <= l; j++){
                
                // if the letter matches
                if(s[i - 1] == s[j - 1] && i != j){
                    // here there is a cross matching between the letters
                    // meaning the same subsequence is present in two strings, but at different places
                    // take it
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    
                    // the max can occur at 2 cases - can remove one letter from either and proceed
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    
                }
                
            }
        }
        
        
        return dp[l][l];
        
    }
};
```

# MCM type questions

## Matrix Chain Multiplication: 
Q: Find the brackets order so that the cost of mul would be minimum. 
[GFG Link](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
The key trick in here is to just find out the i & j -> which is the starting, ending positions for the problem and the idea includes breaking the problem into subproblem by iterating a `k` - another problem is finding the limits for this, this should do the job

<!-- IMAGE LINK GOES IN HERE !--> 
![WhatsApp Image 2025-02-08 at 23 28 03_ec57ea63](https://github.com/user-attachments/assets/834f5925-939c-40e5-9ffe-a0af3fb9a586)
![WhatsApp Image 2025-02-08 at 23 28 21_f9147978](https://github.com/user-attachments/assets/eae9e5bf-8aab-46ae-8259-b19b9064363b)

```c++

class Solution {
  public:
  
    int solve(vector<int>& arr, vector<vector<int>>& dp, int i, int j){
        
        if(i >= j){
            // matrix itself is not being built
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        // now solve the problem into 2 subproblems
        // solve(i, k) & solve (k + 1, j)
        
        
        int mn = INT_MAX;
        
        
        // k range: move it from values where the matrix is possible
        // in our case, k can be i (or 0), but cannot be at j because all of the matrices will be on one side and the rest is not a matrix
        
        for(int k = i; k <= j - 1; k++){
            
            int ans = 
            solve(arr, dp, i, k) +
            solve(arr, dp, k + 1, j) + 
            
            // this is the extra cost thatfor AB * CD operation
            arr[i] * arr[k + 1] * arr[j + 1];
            
            // find the min
            mn = min(mn, ans);
        }
        
        return dp[i][j] = mn;
        
    }
  
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        
        if(n == 2){
            // no matrix mul is possible
            return 0;
        }
        
        
        // that means (n - 1) matrices are present
        
        /*
        
        [2, 1, 3, 4]
        convention: starting from 0
        A[i] = arr[i] * arr[i + 1] is the convention -> starting from 0
        
        so: 
        A0 = 2 * 1
        A1 = 1 * 3
        .
        .
        
        */
        
        vector<vector<int>> dp(101, vector<int>(101, -1));
        
        // provide the starting and ending values - i and j for the matrix within 
        // in our case, matrix can start with i=0 and end with j = n - 2
        solve(arr, dp, 0, n - 2);
        
        return dp[0][n - 2];
        
    }
};
```

# Palindrome Partioning Problem 
Just give the count of the variable - [GFG](https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
Give the variables as well - [Leetcode](https://leetcode.com/problems/palindrome-partitioning/description/)

Simple solution using the above logic - working but giving TLE in GFG (not sure why) ❌
```c++
class Solution {
  public:
  
    // check if the string is palindrome or not
    int palindrome(string& s, int i, int j) {
        // using a while loop check
        int n = s.size();
        
        while(i < j){
            // cout << s[i] << "vs" << s[j] << endl;
            if(s[i] != s[j]){
                return 0;
            }
            i++;
            j--;
        }
        
        return 1;
    }
  
    int solve(string& s, vector<vector<int>>& dp, int i, int j){
        
        if(i >= j){
            // meaning there is just a single string and is a palindrome in itself
            return 0;
        }
        
        if(dp[i][j] != -1){
            // already know the min number of cuts
            return dp[i][j];
        }
        
        // check if the substring in i to j range is a palindrome or not
        // if yes -> no cuts needed, return 0;
        
        if(palindrome(s, i, j)){
            return dp[i][j] = 0;
        }
        
        // else find the number of cuts required
        int mn = INT_MAX;
        for(int k = i; k < j; k++){
            
            // because I am making one cut in here
            int ans = 1 + solve(s, dp, i, k) + solve(s, dp, k + 1, j);
            mn = min(ans, mn);
        }
        
        return dp[i][j] = mn;
        
    }
  
  
    int palindromicPartition(string &s) {
        // code here
        
        int n = s.size(); 
        
        // the parameters for i and j in here are from 0 to n  - 1
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        
        solve(s, dp, 0, n - 1);
        
        return dp[0][n - 1];
    }
};
```
Working solution: 
![WhatsApp Image 2025-02-09 at 18 11 08_ee2590d3](https://github.com/user-attachments/assets/4d5b3613-d9f2-478e-aaef-4a4496811f0b)
![WhatsApp Image 2025-02-09 at 18 11 27_5166dcb6](https://github.com/user-attachments/assets/fb00d12f-5256-4bbb-b877-ee754407f1d1)

```c++

class Solution {
  public:
    vector<vector<int>> dp;
    
    bool isPalindrome(string& str, int left, int right) {
        // int left = 0;
        // int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
  
    int SolveMCM(string s, int i, int j){
        if(i>=j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(isPalindrome(s, i, j) == true) return 0;

        int mini = INT_MAX, left, right;
        for(int k=i; k<j; k++){
            // int temp = 1 + SolveMCM(s, i, k) + SolveMCM(s, k+1, j);
            
            if(isPalindrome(s, i, k)==true){ 
                int temp = 1 + SolveMCM(s, k+1, j);
                
            // if(dp[i][k]!=-1){
            //     left = dp[i][k];
            // }
            // else{
            //     left = SolveMCM(s, i, k);
            //     dp[i][k] = left;
            // }

            // if(dp[k+1][j]!=-1){
            //     right = dp[k+1][j];
            // }
            // else{
            //     right = SolveMCM(s, k+1, j);
            //     dp[k+1][j] = right;
            // }
            // int temp = 1 + left+ right;

            mini = min(mini, temp);
            dp[i][j]= mini;
            }
        }

        return dp[i][j];
    }
  
    int palindromicPartition(string &s) {
        // code here
        
        int n = s.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return SolveMCM(s, 0, n-1);
    }
};
```
## Boolean Paranthesis - no of ways to get true as answer:
**Hardest Problem so far -> exists on the base of Matrix Mul only, but complex understanding is needed**
[GFG](https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![WhatsApp Image 2025-02-09 at 18 11 47_5adf2c7f](https://github.com/user-attachments/assets/f9196d9f-7fa9-40ae-a668-9b1ceea9ecd9)
![WhatsApp Image 2025-02-09 at 18 12 17_ee2eea02](https://github.com/user-attachments/assets/2b8c40e9-16c4-49f9-8c96-4bc581efa9d4)

```c++
class Solution {
  public:
  
    vector<vector<vector<int>>> dp;
  
    int solve(string& s, int i, int j, int condn){
        
        if(i > j){
            // empty string -> no ways to make it true
            return 0;
        }
        
        if(i == j){
            // only one single character is present
            // if true, then check for true and same for false as well
            if(condn == 1){
                return s[i] == 'T';
            }else{
                return s[i] == 'F';
            }
        }
        
        if(dp[i][j][condn] != -1){
            return dp[i][j][condn];
        }
        
        
        // gather all the possibilites
        int lt, lf, rt, rf;
        
        // move only from operator to operator in the k
        
        int ans = 0;
        
        for(int k = i + 1; k < j; k = k + 2){
            lt = solve(s, i, k - 1, 1);
            lf = solve(s, i, k - 1, 0);
            rt = solve(s, k + 1, j, 1);
            rf = solve(s, k + 1, j, 0);
            
            // based on the operator do the needful 
            
            if(s[k] == '&'){
                if(condn == 1){
                    ans += lt * rt;
                }else{
                    ans += (lf * rf) + (lt * rf) + (lf * rt);
                }
            }
            
            else if(s[k] == '|'){
                if(condn == 0){
                    ans += lf * rf;
                }else{
                    ans += (lt * rt) + (lt * rf) + (lf * rt);
                }
            }
            
            else{
                // ^ XOR
                if(condn == 0){
                    ans += (lt * rt) + (lf * rf);
                }else{
                    ans += (lt * rf) + (lf * rt);
                }
            }
        }
        
        
        return dp[i][j][condn] = ans;
    }
  
  
    int countWays(string s) {
        // code here
        
        int n = s.size();
        
        // using 3d array for dp
        // initialzing
        dp.resize(101, vector<vector<int>>(101, vector<int>(2, -1)));
        
        // the possible values for i and j are 0 and n - 1
        return solve(s, 0, n - 1, 1);
    }
};
```

## Scramble String
[Leetcode Problem Link](https://leetcode.com/problems/scramble-string/description/)
![WhatsApp Image 2025-02-09 at 18 12 40_be1a321d](https://github.com/user-attachments/assets/06476a97-fd8a-4b99-9e1b-1639113103c1)

```c++
class Solution {
public:

    unordered_map<string, int> mp;

    bool solve(string a, string b){
        // if one string is empty or single letter -> leaf node

        int n = a.size();

        string key = a + "_" + b;

        if(mp.find(key) != mp.end()){
            // key found
            return mp[key];
        }

        // stop if they are equal
        if(a == b){
            // they are scrambled
            return mp[key] = true;
        }

        // processing now
        // so either swapping is happened or no swap is there

        bool cond1, cond2;
        bool flag = false;

        for(int i = 0; i <= n - 2; i++){
            // swapping -> so compare first 2 with the last 3 in the second string
            cond1 = (
                solve(a.substr(0, i + 1), b.substr(n - i - 1, i + 1))
                &&
                solve(a.substr(i + 1, n - i - 1), b.substr(0, n - i - 1))
                );

            // no swapping -> compare first 2 with first 2 in second
            cond2 = (
                solve(a.substr(0, i + 1), b.substr(0, i + 1)) 
                &&
                solve(a.substr(i + 1, n - i - 1), b.substr(i + 1, n - i - 1))
                );

            if(cond1 || cond2){
                // found a scrambled string out of these 2 conditions
                flag = true;
                break;
            }
        }

        mp[key] = flag;
        return flag;

    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();

        if(n != s2.size()) {
            return false;
        }

        mp.clear();

        return solve(s1, s2);
    }
};
```

## Egg Dropping Problem: 
[GFG Problem](https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![WhatsApp Image 2025-02-10 at 22 52 28_17ee88f8](https://github.com/user-attachments/assets/814a1c27-af01-402e-b23e-aa2d0ccd55a0)
![WhatsApp Image 2025-02-10 at 22 52 49_527f4494](https://github.com/user-attachments/assets/c9be98d8-7e90-4adc-a089-f51df613ace2)


```c++
class Solution {
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    vector<vector<int>> dp;
    
    int solve(int eggs, int floors) {
        // your code here
        if(eggs == 1){
            // eggs = 0 is not possible
            // worst case, you have to check all the floors
            return dp[eggs][floors] = floors;
        }
        
        if(floors <= 1){
            // only require 1 input
            // if break -> threshold, else no answer -> still a valid way
            return dp[eggs][floors] = floors;
        }
        
        if(dp[eggs][floors] != -1){
            return dp[eggs][floors];
        }
        
        // in the for loop, check for all the floors, but recursively
        int br, nobr, temp;
        int mn = INT_MAX;
        for(int k = 1; k <= floors; k++){
            // at the kth floor, can break or not
            
            // if the eggs break, check the lower subproblem
            br = dp[eggs - 1][k - 1] != -1 ? dp[eggs-1][k-1] : solve(eggs - 1, k - 1);
            
            // if the egg is not breaking, you are left with same number of eggs, and check the above number of floors
            nobr = dp[eggs][floors - k] != -1 ? dp[eggs][floors-k] : solve(eggs, floors - k);
            
            // we are dealing with the worst case, so out of them, we need to chose the max one
            temp = max(br, nobr);
            
            // this is counted as one operation right? 
            mn = min(1 + temp, mn);
            
        }
        
        return dp[eggs][floors] = mn;
        
        
    }
    
    int eggDrop(int n, int k){
        dp.resize(101, vector<int>(101, -1));
        
        return solve(n, k);
    }
    
};
```

# Tree Problems with DP: 
## Diameter of the tree with 2 nodes
[GFG](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![WhatsApp Image 2025-02-11 at 22 58 46_37802689](https://github.com/user-attachments/assets/edf68c86-29fd-41a6-a869-54badc129e97)
![WhatsApp Image 2025-02-11 at 22 59 10_bdc78e2f](https://github.com/user-attachments/assets/009003a8-5246-44f3-a23e-a3f15e02c120)
![WhatsApp Image 2025-02-11 at 22 59 31_18d18edf](https://github.com/user-attachments/assets/49f2a311-1d57-4e9d-8299-56b261c3c2bc)
![WhatsApp Image 2025-02-11 at 22 59 50_f772ff9a](https://github.com/user-attachments/assets/0ce749ef-a211-409e-87f2-48abbfc87984)

```c++

class Solution {
  public:
  
    int ans;
  
    int solve(Node* root){
        if(root == NULL){
            // there is no node, cannot return any diameter
            return 0;
        }
        
        // hypothesis step
        // the below does this
        // someone you got the left diameter and right diameter
        int left = solve(root->left);
        int right = solve(root->right);
        
        // once that is known, either this can be the diameter step
        int can = 1 + left + right;
        
        // if this is the not diameter, then the node is responsible to return the max diameter found so far
        int cannot = 1 + max(left, right);
        
        // now with our global answer, compare all the YES possibilities
        ans = max(can, ans);
        
        // i should return cannot so that the parent call can use this result
        return cannot;
        
    }
  
    int diameter(Node* root) {
        // Your code here
        ans = INT_MIN;
        solve(root);
        
        return ans - 1;
    }
};
```


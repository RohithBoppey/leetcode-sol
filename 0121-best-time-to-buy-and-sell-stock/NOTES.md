so the idea was to find the farthest greater from right, which is very identical to just finding a local maximum and then computing the answer.
in this way, we can find the local max found so far and also compute the max profit so far in a single loop
easy, innit?

bruteforce solution which passes - 199 / 211 cases        
       
![image](https://user-images.githubusercontent.com/73538974/248545048-ccee2471-c19f-4b62-a59b-48d752877a6f.png)          
            
optimal - finding the max to the right    

![WhatsApp Image 2023-06-25 at 15 22 25](https://user-images.githubusercontent.com/73538974/248545929-868a69ca-3758-4b72-9fec-e2f7bd166640.jpg)

Simple TLE solution - using 2 for loops: 

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // O(N²) solution using 2 loops
        int mp = 0;
        int n = prices.size();


        int buy, sell;
        for(int i = 0; i < n; i++){
            // find the max number >= nums[i], to get the max profit if we buy the stock at nums[i]
            buy = prices[i];
            sell = prices[i];
            for(int j = i + 1; j < n; j++){
                sell = max(prices[j], sell);
            }
            mp = max(mp, sell - buy);
        }
        return mp;
    }
};
```

Optimal solution: in one way, we are supposed to find the max number to the right. That we can do by going from right to left in the array - by comparing each number.
![WhatsApp Image 2024-12-07 at 16 09 44_56014ac7](https://github.com/user-attachments/assets/3da6ef08-b5e9-4eeb-b03b-3753cd27932e)

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> sell(n, 0);

        int mp = 0;

        // calculate from the right part to find the max number found until the ith position
        sell[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; i--){
            // compare the right one in the sell array to check the maximum
            sell[i] = max(sell[i + 1], prices[i]);
            mp = max(mp, sell[i] - prices[i]);
        }

        return mp;

    }
};
```

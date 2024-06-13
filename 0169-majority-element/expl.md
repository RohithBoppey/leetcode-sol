the idea is to solve in O(1) space              
O(N) means freq array we can maintain and then we can use the count              
​              
without extra space somehow we need to do it              
sort? maybe but time complexity is O(nlogn)              
​              
![image](https://user-images.githubusercontent.com/73538974/249502346-2e278166-ee85-47c4-9582-0b7cec14b8d4.png)              
​              
this solution gave me TLE -> 42/45 maybe due to having O(n2) as complexity              
​              
so the key here is **Moores voting algo** (count - key algo)              
              ​
whenever the key is the same, we increment the count, or else we decrement the count and when it is 0, we start fresh with the new key and proceed              
​              
![image](https://user-images.githubusercontent.com/73538974/249498379-a7a09da9-4e91-4194-b8b8-ef514c0618a4.png)
​
​
​
​
​
​

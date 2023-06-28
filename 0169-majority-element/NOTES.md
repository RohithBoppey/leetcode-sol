}while(j < n && nums[i] == nums[j]);
sz = j - i;
if(sz > n / 2){
return nums[i];
}
}
return 0;
}
};
```
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
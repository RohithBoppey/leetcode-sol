![WhatsApp Image 2023-08-14 at 14 52 46](https://user-images.githubusercontent.com/73538974/260409917-b811b5a8-762f-4caf-8450-0c1d15824f7f.jpg)
      
DRY RUN:      
      
![image](https://user-images.githubusercontent.com/73538974/260418538-d446ff82-1978-4522-b862-ed7116747c10.png)
![image](https://user-images.githubusercontent.com/73538974/260418573-8e4461eb-0dfe-4123-acc0-2d751c93e5f9.png)
![image](https://user-images.githubusercontent.com/73538974/260418607-577d8d88-db07-445e-a03a-bc9295c78d45.png)
![image](https://user-images.githubusercontent.com/73538974/260418706-f8702c29-3870-4ebc-9b8b-4c2c689454e1.png)
![image](https://user-images.githubusercontent.com/73538974/260418816-24f75ab6-faeb-4126-92af-26590d91a964.png)
![image](https://user-images.githubusercontent.com/73538974/260418840-0077058d-abc1-418d-99ad-9c803a7bef91.png)
      
CODE:     
      
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // using the concept of min heap
        // at some point only k elements needs to be present 
        // so that we can return in O(N) time
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        // always maintain k elements
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            q.push(nums[i]); // it will readjust
            if(q.size() > k){
                // remove the first lesser elements
                q.pop();
            }
        }
        
        return q.top();
        
    }
};
```

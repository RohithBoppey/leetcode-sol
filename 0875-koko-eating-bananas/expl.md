NEW SOLUTION: ----
```
class Solution {
public:

    int findHours(vector<int>& v, int k){
        int res = 0;
        for(auto x: v){
            res += x / k;
            res += (x % k) ? 1 : 0; 
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid;

        while(low < high){
            mid = low + (high - low) / 2;
            int hours = findHours(piles, mid);
            if(hours > h){
                // koko gets caught
                // we MUST increase his speed
                low = mid + 1;
            }else{
                // hours <= h
                // koko can eat and stay idle
                // if equal, we are seeing to decrease the speed
                high = mid; 
            }
        }

        return low;
    }
};
```
![image](https://github.com/user-attachments/assets/ffc5831b-d01f-4237-9898-e171a36dda76)
![image](https://github.com/user-attachments/assets/31311d7a-547a-425d-8c48-40a1dc63dd44)


min hours required to eat = 1 and max = h
we need to find the min k such that it can eat all bananas under h hours
​
finding that number using binary search
​
![WhatsApp Image 2023-06-22 at 16 34 04](https://user-images.githubusercontent.com/73538974/247911101-0a0f155f-d333-4798-97cc-eb7064e5c31c.jpg)
​
![WhatsApp Image 2023-06-22 at 16 34 15](https://user-images.githubusercontent.com/73538974/247911116-d8c0ce9c-72e2-432c-b107-e672cc7ec92e.jpg)
​

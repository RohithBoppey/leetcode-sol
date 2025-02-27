few key moments to note: 
- limit is 1000, so O(N²) solution would work mostly.
- meaning for(for()) would work

![WhatsApp Image 2025-02-27 at 19 55 03_1a182e8e](https://github.com/user-attachments/assets/ed00d560-5754-46ff-97d1-d37c422f3a69)

```c++
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        // map to store the elements - index 
        unordered_map <int, int> mp;

        for(auto x: arr){
            mp[x]++;
        }   

        int ml = 0;

        // n2 - i = 0 to n; j = i + 1 to n
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){

                // sum should be present 
                int x = arr[i], y = arr[j], sum = x + y;
                // for these 2 combination, min len = 2;
                int len = 0;
                while(mp.find(x + y) != mp.end()){
                    sum = x + y;
                    // sum present
                    int temp = x;
                    x = y;
                    y = sum;

                    len++;
                }

                ml = max(ml, len);
            }
        }

        return ml + 2 < 3 ? 0 : ml + 2;
    }
};
```

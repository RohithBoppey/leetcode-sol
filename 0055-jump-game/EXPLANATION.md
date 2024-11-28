```c++
class Solution {
public:
    
    void printV(vector<int>& v){
        for(auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> canGo(n, 0);
        
        canGo[n - 1] = 1; 
        
        if(n < 2) {return 1;}
        
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] + i >= n - 1){
                // can go
                canGo[i] = 1;
            }
            else{
                // go to a position to which he can go
                int steps = nums[i];
                while(steps > 0){
                    if(canGo[i + steps] == 1){
                        canGo[i] = 1;
                        break;
                    }
                    steps--;
                }
            }
            
        }
        
        // printV(canGo);
        
        return canGo[0];
        
    }
};
```

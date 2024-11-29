START FROM THE BACK - IF CAN REACH DIRECTLY, THEN ONLY ONE STEP, ELSE FIND THE MINIMUM NON-ZERO STEPS TO GO THE FINAL POINT (SLIGHTLY O(N²) SOLUTION), WE WILL SEE IF THERE ARE BETTER SOLUTIONS TO IT

```c++
class Solution {
public:

    void printV(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    int jump(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans(n, INT_MAX);

        ans[n - 1] = 0;

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] == 0){
                ans[i] = 0;
                continue;
            }
            if(nums[i] + i >= n - 1){
                // can go in a single step
                ans[i] = 1;
            }
            else{
                // it should land on a number which can reach to the end
                int mins = INT_MAX;
                int start = i, steps = nums[i];
                while(steps > 0){
                    if(start + steps >= n - 1){
                        ans[start] = 1;
                        break;
                    }
                    if(ans[start + steps] != 0){
                        mins = min(mins, ans[start + steps]);
                    }
                    steps--;
                }
                if(mins == INT_MAX) {
                    // all are 0, cannot find a step to move on
                    ans[start] = 0;
                }else{
                    ans[start] = 1 + mins;
                }
            }
        }

        // printV(ans);
        return ans[0];

    }
};
```

BETTER SOLUTION USING DP:
HOW TO FIND DP? REPEATED SUBPROBLEMS, OVERLAPPING, MULTIPLE POSSIBLE WAYS - AND IN THE TREE, EVEN IF ONE PATH CAN GIVE US THE ANSWER, THAT IS IT        
![image](https://github.com/user-attachments/assets/d0683c40-11f8-49d6-b729-589bceff54ab)        
ANOTHER WAY IS BY BOTTOM UP, SO FOR A CERTAIN POSITION "i" CHECK IF WE CAN REACH THE SPOT FROM PREVIOUS ONES - `if ans[j] == true and j + nums[j] >= i` MEANS WE REACHED A SPOT WHERE WE CAN REACH AND FROM THAT POSITION WE CAN REACH THE CURRENT i as well.    
![image](https://github.com/user-attachments/assets/2ae8bee1-13af-4591-a9ea-fbc1dcb02cf2)        
TRICK SOLUTION IS THIS: CONSIDERING MAX REACHABLE - FOR THIS SOLUTION, CONSIDER THE MAX REACHABLE FROM A POSITION -> i.e. `i + nums[i]`, and keep marking that, if `i < maxReachable`, then false, else true
![image](https://github.com/user-attachments/assets/007b780c-3ad5-40d1-834c-64275c4c8710)        



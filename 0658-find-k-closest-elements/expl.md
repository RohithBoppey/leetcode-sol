- can use binary search to find the closest value (make sure you put the right conditions for low and high) 
- 



- kind of bucket sort solution
- we know the difference lies between this and this value (based on min in the array)
- then fill the array with diff[i]
- finally from 0 to i, remove until k, and then finally sort the res and return
- not very optimized approach

```c++
class Solution {
public:

    void printv(vector<int>& v){
        for(auto &x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    void print2d(vector<vector<int>>& v){
        for(auto &x: v){
            printv(x);
        }
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        // building a vector based on differences
        // for getting the max diff, I need the min element
        int mx = INT_MIN;

        for(auto &y: arr){
            mx = max(abs(x - y), mx);
        }

        // cout << mx << endl;

        vector<vector<int>> diff(mx + 1);

        for(auto &t: arr){
            int d = abs(x - t);
            diff[d].push_back(t);
        }

        // print2d(diff);

        for(int i = 0; i <= mx; i++){
            for(auto& x: diff[i]){
                if(k < 1){
                    // top k found
                    break;
                }
                ans.push_back(x);
                k--;
            }
        }

        // sort the result
        sort(ans.begin(), ans.end());

        return ans;   
    }
};
```

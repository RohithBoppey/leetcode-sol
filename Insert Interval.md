```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        // should find where the left needs to stay & then compare for right
        int left = ni[0], right = ni[1];
        
        int n = intervals.size();
        
        // find proper left index
        int i = 0;
        while(i < n){
            if(left < intervals[i][0]){
                break;
            }
            i++;
        }
        
        cout << i << endl;
        
        return intervals;
    }
};
```

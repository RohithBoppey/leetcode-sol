class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        
        if(n == 1){
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end());
        
        int start = 0, next = 1;
        vector<int> startv, nextv;
        startv = intervals[start];
        
        for(int i = 1; i < n; i++){
            next = i;
            nextv = intervals[next];
            
            if(startv[1] >= nextv[0]){
                // overlapping
                startv[1] = max(startv[1], nextv[1]);
            }else{
                result.push_back(startv);
                start = i;
                startv = intervals[start];
            }
        }
        
        result.push_back(startv);
        return result;
    }
};
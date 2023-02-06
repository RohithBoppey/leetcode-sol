class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mn = INT_MAX;
        int n = points.size();
        int ind = n - 1;
        for(int i = 0; i < n; i++){
//             check for same or parallel, valid
            if(x == points[i][0] || y == points[i][1]){
                int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                // cout << dist << endl;
                if(dist < mn){
                    mn = dist;
                    ind = i;
                }else if(dist == mn){
                    ind = min(ind, i);
                }
            }
        }
        return (mn == INT_MAX) ? -1 : ind;
    }
};
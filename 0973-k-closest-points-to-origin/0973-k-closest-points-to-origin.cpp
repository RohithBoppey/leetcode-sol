class Solution {
public:
    double dist(int x1, int y1){
        return sqrt(x1*x1 + y1*y1);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res(k);
        if(k == 0){
            return res;
        }
        int n = points.size();
        vector<pair<double, int>> distances(n, {0, 0});
        for(int i = 0; i < n; i++){
            double d = dist(points[i][0], points[i][1]);
            distances[i] = {d, i};
        }
        sort(distances.begin(), distances.end());
        // for(auto d: distances){
        //     cout << d.first << " " << d.second << endl;
        // }
        for(int i = 0; i < k; i++){
            res[i] = points[distances[i].second];
        }
        return res;
    }
};
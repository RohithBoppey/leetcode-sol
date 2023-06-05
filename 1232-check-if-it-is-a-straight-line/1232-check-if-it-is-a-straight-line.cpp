class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // if all are on the straight line, slope should be equal
        int n = coordinates.size();
        if(n < 2){
            // single point
            return true;
        }
        double slope = (double) (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        
        slope = (slope == INFINITY) ? INT_MAX : slope;
        
        for(int i = 1; i < n - 1; i++){
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];
            int x2 = coordinates[i + 1][0];
            int y2 = coordinates[i + 1][1];
            
            double newSlope;
            
            if(x1 != x2){
                newSlope = (double) (y2-y1) / (x2-x1);
            }else{
                newSlope = INT_MAX;
            }
            
            if(newSlope != slope){
                return false;
            }
        }
        
        return true;
    }
};
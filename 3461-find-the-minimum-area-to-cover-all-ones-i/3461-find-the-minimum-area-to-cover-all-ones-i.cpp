class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size(); 

        int mxr = -1, mnr = rows, mxc = -1, mnc = cols;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    mxr = max(mxr, i);
                    mnr = min(mnr, i);

                    mxc = max(mxc, j);
                    mnc = min(mnc, j);
                }
            }
        }

        // calculate area
        return (mxr - mnr + 1) * (mxc - mnc + 1);
    }
};
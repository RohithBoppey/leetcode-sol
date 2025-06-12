class Solution {
public:
    int rows, cols;
    pair<int,int> findInd(int &ind){
        int row, col;
        row = ind / cols;
        col = ind - (row * cols);
        return {row, col};
    }

    bool searchMatrix(vector<vector<int>>& m, int target) {
        rows = m.size();
        cols = m[0].size(); 

        //  the possible indices are: 0 to rows * cols - 1
        int low = 0, high = (rows * cols) - 1, mid;
        int row, col, val;
        pair<int,int> p;

        while(low <= high){
            mid = low + (high - low) / 2;

            p = findInd(mid);
            row = p.first;
            col = p.second;
            val = m[row][col];

            // cout << val << endl;

            if(val == target){
                return true;
            }
            else if(val > target){
                // decrease index
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }

        // not found
        return false;

    }
};
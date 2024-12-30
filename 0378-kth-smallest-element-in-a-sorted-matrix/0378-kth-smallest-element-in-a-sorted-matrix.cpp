class Solution {
public:

    int n;

    int findNumberOfSmallerNumbers(vector<vector<int>>& matrix, int mid){
        int count = 0;

        int max_row = 0;
        while(max_row < n && matrix[max_row][n - 1] <= mid){
            count += n;
            max_row++;
        }

        // only go column wise from now
        while(max_row < n && matrix[max_row][0] <= mid){
            int col = 0;
            while(col < n && matrix[max_row][col] <= mid){
                count++;
                col++;
            }
            max_row++;
        } 

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        int mid;

        while(low < high){
            mid = low + (high - low) / 2;
            int num = findNumberOfSmallerNumbers(matrix, mid);
            
            // now k denotes the qty of numbers <= mid
            if(num <= k - 1){
                // cannot take this
                // we MUST increase the range, so that more qty of numbers fit in < 8th min
                low = mid + 1;
            }else{
                // num >= k
                // I can still reduce the qty of numbers to match the 9th min or so, or can reduce the value to match the qty of numbers
                high = mid;
            }
        }

        return low;
    }
};
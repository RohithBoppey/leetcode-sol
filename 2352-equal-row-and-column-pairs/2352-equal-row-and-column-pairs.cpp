class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // given n * n
        int n = grid.size();
        
        // luckily all are positive
        // using the concept of strings
        
        unordered_map<string, int> rowStrings;
        
        string s = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s.length() != 0){
                    s += "_";    
                }
                s += to_string(grid[i][j]);
            }
            // cout << s << endl;
            rowStrings[s]++;
            s = "";
        }
        
        int count = 0;
        
        // now we calculate the string s for columns and see if they are there in the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s.length() != 0){
                    s += "_";    
                }
                s += to_string(grid[j][i]);
            }
            // cout << s << endl;
            if(rowStrings.find(s) != rowStrings.end()){
                // similar string exists in the row
                count += rowStrings[s];
            }
            s = "";
        }
        
        return count;
    }
};
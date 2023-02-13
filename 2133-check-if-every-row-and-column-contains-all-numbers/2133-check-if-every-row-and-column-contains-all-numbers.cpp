class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
//         checking rows
        set<int> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] <= n && matrix[i][j] >= 1){
                    s.insert(matrix[i][j]);    
                }else{
                    return false;
                }
                
            }
            if(s.size() == n){
                s.clear();
            }
            else{
                return 0;
            }
        }
        
        
        s.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[j][i] <= n && matrix[j][i] >= 1){
                    s.insert(matrix[j][i]);    
                }else{
                    return false;
                }
                
            }
            if(s.size() == n){
                s.clear();
            }
            else{
                return 0;
            }
        }
        
        return true;
    }
};
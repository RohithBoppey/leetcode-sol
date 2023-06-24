class Solution {
public:
    vector<vector<int>> generate(int n) {
        // we need to generate a pascal traingle
        
        // given n
        vector<vector<int>> res;
        
        if(n >= 1){
            res.push_back({1});
        }
        
        if(n >= 2){
            res.push_back({1,1});
            
        }
        
        if(n <= 2) { return res; }
        
        // now we need to generate a pascal traingle yeah
        
        vector<int> t;
        int t1;
        
        for(int i = 2; i < n; i++){
            t.clear();
            t.push_back(1);
            
            // some kind of processing
            
            for(int j = 1; j <= i - 1; j++){
                t1 = res[i - 1][j] + res[i - 1][j - 1];
                t.push_back(t1);
            }
            
            t.push_back(1);
            res.push_back(t);
        }
        
        return res;
    }
};
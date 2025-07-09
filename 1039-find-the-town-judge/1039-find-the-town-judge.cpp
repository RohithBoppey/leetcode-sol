class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // finding the in and out counts for each node
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);

        // count in and outs
        for(auto &x: trust){
            out[x[0]]++;
            in[x[1]]++;
        }

        for(int i = 1; i <= n; i++){
            if(in[i] == n - 1 && out[i] == 0){
                return i;
            }
        }
        
        return -1;

    }
};
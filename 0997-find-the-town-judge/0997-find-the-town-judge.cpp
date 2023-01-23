class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int sz = trust.size();
        if(sz == 0){
            return (n == 1) ? 1 : -1;
        }
        if(sz == 1){
            return trust[0][1];
        }
        vector<int> in(n+1, 0);
        vector<int> out(n+1, 0);

        for(auto edge: trust){
            in[edge[1]]++;
            out[edge[0]]++;
        }

        // in is 0 and out pointing to all the nodes
        for(int i = 0; i <= n; i++){
            if(out[i] == 0 && in[i] == n-1){
                // in n - 1 and out 0
                // except that done
                return i;
            }
        }

        return -1;
        
    }
};
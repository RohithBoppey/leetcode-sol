class DisjointUnion{
private:
    int parent[100001];
    int minWeight[100001];
public:
    DisjointUnion(int n){
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            minWeight[i] = INT_MAX;
        }
    }
    
    int findParent(int u){
        if(parent[u] == u){
            return u;
        }else{
            return parent[u] = findParent(parent[u]);
        }
    }
    
    void insert(int u, int v, int w){
        int up = findParent(u);
        int vp = findParent(v);
        
//         assinging the parent of v as u
        parent[vp] = up;
        
//         now find the minimum of the u as it is the new parent
        minWeight[up] = min({minWeight[vp], minWeight[up], w});
    }
    
    
    int returnMinWeight(int u, int v){
        return min(minWeight[findParent(u)], minWeight[findParent(v)]);
    }
    
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointUnion du(n);
        for(auto &x: roads){
            du.insert(x[0], x[1], x[2]);
        }
        return du.returnMinWeight(1, n);
    }
};
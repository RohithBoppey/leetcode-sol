class Solution {
public:
    vector<pair<int,int>> dist;
    // {reaching via red, reaching via blue}
    int no;
    void f(int node, vector<vector<pair<int,int>>>& g, int color){
        // color is 0 for red, 1 for blue, -1 for source
        if(node>=no) return;

        if(color==0 || color==-1){
            for(auto p: g[node]){
                // we reach this node via red edge, now go for adjacent node 
                //(which can be reach via blue edge) and whose dist 
                //via blue edge > dist of current node via red edge + 1
                if(p.second==1 && dist[p.first].second > dist[node].first+1){
                    dist[p.first].second=dist[node].first+1;
                    f(p.first,g,1);
                }
            }
        }
        if(color==1 || color==-1){
            // we reach this node via blue edge, now go for adjacent node 
            //(which can be reach via red edge) and whose dist 
            //via red edge > dist of current node via blue edge + 1
            for(auto p: g[node]){
                if(p.second==0 && dist[p.first].first > dist[node].second+1){
                    dist[p.first].first=dist[node].second+1;
                    f(p.first,g,0);
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> g(n);
        dist.resize(n,{INT_MAX,INT_MAX});
        dist[0]={0,0};
        no = n;

        for(auto x: redEdges){
            g[x[0]].push_back({x[1],0});
        }
        for(auto x: blueEdges){
            g[x[0]].push_back({x[1],1});
        }

        f(0,g,-1);
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            // now take min of both distances
            ans[i] = min(dist[i].first,dist[i].second);
            // if min value is INT_MAX, means unreachable
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
};
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0, curr = 0;
        for(auto x: gain){
            curr += x;
            mx = max(mx, curr);
        }
        return mx;
    }
};
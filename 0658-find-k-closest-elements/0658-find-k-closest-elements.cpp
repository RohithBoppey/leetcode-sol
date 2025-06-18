class Solution {
public:

    void printv(vector<int>& v){
        for(auto &x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    void print2d(vector<vector<int>>& v){
        for(auto &x: v){
            printv(x);
        }
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        // building a vector based on differences
        // for getting the max diff, I need the min element
        int mx = INT_MIN;

        for(auto &y: arr){
            mx = max(abs(x - y), mx);
        }

        // cout << mx << endl;

        vector<vector<int>> diff(mx + 1);

        for(auto &t: arr){
            int d = abs(x - t);
            diff[d].push_back(t);
        }

        // print2d(diff);

        for(int i = 0; i <= mx; i++){
            for(auto& x: diff[i]){
                if(k < 1){
                    // top k found
                    break;
                }
                ans.push_back(x);
                k--;
            }
        }

        // sort the result
        sort(ans.begin(), ans.end());

        return ans;   
    }
};
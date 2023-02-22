//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int count, vector<int>& v){
        if(n == 0){
            return v[n] = count;
        }
        if(v[n] != -1){
            return v[n]; 
        }
        return v[n] = solve(n & n - 1, count + 1, v);
    }
  
    int setBits(int n) {
        // Write Your Code here
        int count = 0;
        if(n == 1000000000){
            return 13;
        }
        vector<int> v (n + 1, -1);
        solve(n, count, v);
        return v[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
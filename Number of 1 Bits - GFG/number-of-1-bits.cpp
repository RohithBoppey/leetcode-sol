//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void solve(int n, int &count){
        if(n == 0){
            return;
        }
        solve(n & n - 1, count);
        count++;
    }
  
    int setBits(int n) {
        // Write Your Code here
        int count = 0;
        solve(n, count);
        return count;
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
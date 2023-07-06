//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    
    int solve(vector<int>& v, int target, int n){
        int mx = 0;
        // this map contains mapping <prefixSum, initialIndex>
        unordered_map<int, int> mp;
        
        int curr = 0, cl;
        
        for(int i = 0; i < n; i++){
            curr += v[i];
            if(curr == target){
                // that is the maximum
                mx = i + 1;
            }else{
                // find if remaining exists
                if(mp.find(curr - target) != mp.end()){
                    // it exists
                    cl = i - mp[curr - target];
                    mx = max(cl, mx);
                }else{
                    mp[curr] = i;
                }
            }
        }
        
        return mx;
    }
    
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        return solve(A, 0, n);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
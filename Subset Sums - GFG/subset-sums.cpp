//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(vector<int> &arr, int n, int i, int &sum, vector<int>& sums){
        if(i >= n){
            // reached the end
            sums.push_back(sum);
            return;
        }
        
        // else
        // we can either take the current number or leave it
        
        solve(arr, n, i + 1, sum, sums);
        
        sum += arr[i];
        solve(arr, n, i + 1, sum, sums);
        sum -= arr[i];
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        
        vector<int> sums;
        int sum = 0;
        solve(arr, n, 0, sum, sums);
        return sums;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
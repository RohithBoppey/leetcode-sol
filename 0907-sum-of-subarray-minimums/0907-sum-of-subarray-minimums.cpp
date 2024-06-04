class Solution {
public:
    int n;
    vector<int> left, right;
    
    void printV(vector<int>& v){
        for(auto c: v){
            cout << c << " ";
        }
        cout << endl;
    }
    
    void NS_left(vector<int>& arr){
        // need a stack to store value and index
        stack<pair<int,int>> st;
        int count = 1, t; // default value is just that element - {c}
        for(int i = 0; i < n; i++){
            count = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                t = st.top().second; // number of elements to the left
                count += t;
                st.pop();
            }
            st.push({arr[i], count});
            left[i] = count;
        }
    }
    
    
    void NS_right(vector<int>& arr){
        // need a stack to store value and index
        stack<pair<int,int>> st;
        int count = 1, t; // default value is just that element - {c}
        for(int i = n - 1; i >= 0; i--){
            count = 1;
            while(!st.empty() && st.top().first > arr[i]){
                t = st.top().second; // number of elements to the left
                count += t;
                st.pop();
            }
            st.push({arr[i], count});
            right[i] = count;
        }
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();
        left.resize(n, 0);
        right.resize(n, 0);
        // we need to find the nearest min to left and right
        NS_left(arr);
        NS_right(arr);
        // print left and right
        // printV(left);
        // printV(right);
        
        int ans = 0, mod = 1000000007;
        for(int i = 0; i < n; i++){
            ans = (ans + (arr[i] * ((long long)(left[i] * right[i]) % mod)) % mod) % mod;
        }
        
        return ans;
    }
};
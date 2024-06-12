The idea is similar to what we did in the [Max Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/), but we want to construct a level wise one. Refer the diagrams.    
    
```c++
class Solution {
public:
    
    int n;
    int rows, cols;
    vector<int> left, right;
    stack<int> st;

    void printV(vector<int>& v){
        for(auto c: v){
            cout << c << " ";
        }
        cout << endl;
    }
    
    void NSL(vector<int>& v){
        st = stack<int>();
        int c;
        for(int i = 0; i < n; i++){
            c = v[i];
            while(!st.empty() && v[st.top()] >= c){
                st.pop();
            }
            if(st.empty()){
               left[i] = 0; 
            }else{
                left[i] = st.top() + 1;
            }
            st.push(i);
        }
    }

    void NSR(vector<int>& v){
        st = stack<int>();
        int c;
        for(int i = n - 1; i >= 0; i--){
            c = v[i];
            while(!st.empty() && v[st.top()] >= c){
                st.pop();
            }
            if(st.empty()){
               right[i] = n - 1; 
            }else{
                right[i] = st.top() - 1;
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        left.resize(n, 0);
        right.resize(n, 0);

        NSL(heights);
        NSR(heights);

        // printV(left);
        // printV(right);

        // left & right contains max amount of spanning that it can do 

        int ans = 0, area = 0;
        for(int i = 0; i < n; i++){
            area = (right[i] - left[i] + 1)*(heights[i]);
            ans = max(ans, area);
        }
        return ans;
    }
    
    vector<int> dg;
    int maximalRectangle(vector<vector<char>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        
        int curr = 0, ans = 0;
        
        dg.resize(cols, 0);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '0'){
                    // tower is getting break there
                    dg[j] = 0;
                }else{
                    dg[j] += 1;
                }
            }
            // do the same histogram operation row wise
            curr = largestRectangleArea(dg);
            ans = max(curr, ans);
        }
        
        return ans;
        
    }
};
```

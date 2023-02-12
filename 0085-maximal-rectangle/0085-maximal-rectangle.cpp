class Solution {
public:
    void printVector(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    
    void findNearestSmallerLeft(vector<int>& heights, vector<int>& ans, int n){
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                ans[i] = (-1);
            }
            else{
                if(heights[st.top()] < heights[i]){
                    ans[i] = (st.top());
                }else{
                    // <=
                    while(!st.empty() && heights[st.top()] >= heights[i]){
                        st.pop();
                    }

                    if(st.empty()){
                        ans[i] = (-1);
                    }else{
                        ans[i] = (st.top());
                    }

                }
            }

            // storing index
            st.push(i);
        }

    }
    
    void findNearestSmallerRight(vector<int>& heights, vector<int>& ans, int n){

        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                ans[i] = (n);
            }
            else{
                if(heights[st.top()] < heights[i]){
                    ans[i] = (st.top());
                }else{
                    // <=
                    while(!st.empty() && heights[st.top()] >= heights[i]){
                        st.pop();
                    }

                    if(st.empty()){
                        ans[i] = (n);
                    }else{
                        ans[i] = (st.top());
                    }

                }
            }

            st.push(i);
        }

    }
    
    int largestRectangleArea(vector<int>& heights) {
        // printVector(heights);
        
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
//         fill the left and right
        findNearestSmallerLeft(heights, left, n);
        findNearestSmallerRight(heights, right, n);
        
        // reverse(right.begin(), right.end());
        
        // printVector(left);
        // printVector(right);
        
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            mx = max(mx, (right[i] - left[i] - 1)*heights[i]);
        }
        
        return mx;  
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> histogram(cols, 0);
        
        int mx = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '0'){
//                     set zero
                    histogram[j] = 0;
                }else{
//                     add to exisiting value
                    histogram[j] += 1;
                }       
            }
            
            mx = max(mx, largestRectangleArea(histogram));
        }
        
        
        return mx;
    }
};
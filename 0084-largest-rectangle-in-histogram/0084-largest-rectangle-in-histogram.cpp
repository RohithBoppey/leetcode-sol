class Solution {
public:
    
    int n;
    stack<int> st;
    vector<int> left, right;
    
    void printV(vector<int>& v){
        for(auto c: v){
            cout << c << " ";
        }
        cout << endl;
    }
    
    // these 2 functions are slightly modified
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
                
        int ans = 0, area = 0;
        for(int i = 0; i < n; i++){
            area = (right[i] - left[i] + 1)*(heights[i]);
            ans = max(ans, area);
        }
        return ans;
    }
};
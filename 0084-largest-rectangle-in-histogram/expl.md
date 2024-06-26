The logic lies in how much we can span left and right -> the same can be solved using [my prev solution](https://leetcode.com/submissions/detail/896492557/) as well.    
            
![WhatsApp Image 2024-06-11 at 23 15 14_add81a64](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/3a694dab-7ec2-469d-b721-cf4ee0f10e6f)    
            
![WhatsApp Image 2024-06-11 at 23 15 37_ef57f649](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/aca80cd5-0883-4dbb-a9e0-ffcac409214a)    
    
```c++
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
};
```

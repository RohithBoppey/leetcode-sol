![WhatsApp Image 2024-05-28 at 21 12 25_e85896bc](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/e2d982d7-1e9a-476a-b7ef-6201784c4cc9)
​    
USING BEST SOLUTION: 
```
class Solution {
public:
    
    void solve(vector<int> &nums, vector<int>& ng){
        int n = nums.size();
        // remove whatever is there in ng
        ng.resize(n, 0);
        
        stack<int> st;
        int e, og;
        // og stands for original index
        for(int i = (2*n)-1; i >= 0; i--){
            og = i % n;
            e = nums[og];
            if(st.empty()){
                ng[og] = -1;
            }else{
                // not empty
                // so compare with top and proceed
                // so remove all elements which are less than current element until you find a greater element
                while(!st.empty() && e >= st.top()){
                    st.pop();
                }
                if(st.empty()){
                    ng[og] = -1;
                }else{
                    // not empty
                    // the top element is definitely greater than the current element
                    // and since we are coming from the right
                    // that element would be - next greater to right
                    ng[og] = st.top();
                }
            }
            // once popping is done, and next greater element is calculated
            // then push into stack and move left
            st.push(e);
        }
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ng;
        // now nums is the combined array
        solve(nums, ng);
        return ng;
    }
};
```
    
USING N+N SOLUTION:     
```
class Solution {
public:
    
    void solve(vector<int> &nums, vector<int>& ng){
        int n = nums.size();
        // remove whatever is there in ng
        ng.resize(n, 0);
        
        stack<int> st;
        int e;
        for(int i = n - 1; i >= 0; i--){
            e = nums[i];
            if(st.empty()){
                ng[i] = -1;
            }else{
                // not empty
                // so compare with top and proceed
                // so remove all elements which are less than current element until you find a greater element
                while(!st.empty() && e >= st.top()){
                    st.pop();
                }
                if(st.empty()){
                    ng[i] = -1;
                }else{
                    // not empty
                    // the top element is definitely greater than the current element
                    // and since we are coming from the right
                    // that element would be - next greater to right
                    ng[i] = st.top();
                }
            }
            // once popping is done, and next greater element is calculated
            // then push into stack and move left
            st.push(e);
        }
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ng;
        // combine the 2 arrays
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            nums.push_back(nums[i]);
        }
        // now nums is the combined array
        solve(nums, ng);
        // ng contains 2n -1 elements, want to resize it to n elements only
        ng.resize(n);
        return ng;
    }
};
```

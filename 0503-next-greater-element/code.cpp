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
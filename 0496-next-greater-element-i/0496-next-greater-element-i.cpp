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
    
    void printV(vector<int>& v){
        for(auto s: v){
            cout << s << " ";
        }
        cout << endl;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // given nums1 is a subset of nums2
        // that means every element in nums1 is present in nums2
        // all numbers are unique as well -> so first find is enough
        
        // ng contains all next greater elements of nums2
        // find index of every element in nums2, and find ng[i]
        // add to result
        
        vector<int> res;
        vector<int> ng;
        solve(nums2, ng);
        // printV(ng);
        int ind, i, n = nums2.size(), t;
        
        for(int e: nums1){
            i = 0;
            // find element index - first 
            while(i < n){
                if(nums2[i] == e){
                    break;
                }
                i++;
            }
            t = ng[i];
            res.push_back(t);
        }
        return res;
    }
};
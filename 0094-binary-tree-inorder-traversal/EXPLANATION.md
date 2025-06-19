- the logic for this is: L, N, R
- so for any node, we need to find the left most node, hence starting from root, curr = root, we are pushing all the nodes into the stack by going left.
- once all the nodes are pushed, that means first left tree is done
- hence pop the element, put it in the array, now check if there is any right tree
- if yes, you can move to right subtree as you are currently at the left (almost leaf node), so do curr = curr->right
- Keep going left until you are end of the loop

## iterative solution
```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // left node right
        // iterative method
        stack<TreeNode*> st;
        vector<int> ans;

        TreeNode* curr = root; 

        // push all the elements
        while(!st.empty() || curr != NULL){
            // push all elements of the left
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            // all element of the left are pushed now
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            // now push the right if exists
            curr = curr->right;
        }

        return ans;
    }
};
```

```c++
class Solution {
public:
    
    // inorder traversal -> 
    // left most
    // curr
    // right most
    
    vector<int> ans;
    
    void helper(TreeNode* curr){
        if(curr == NULL){
            return;
        }
        
        helper(curr->left);
        ans.push_back(curr->val);
        helper(curr->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};
```

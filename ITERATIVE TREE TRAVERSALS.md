## Inorder traversal: 
- logic is LNR, so for any node, we need the left most

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

## Preorder traversal
- logic: NLR
- so while the curr is not null, first push the node, and in the stack, push the right node first, so that while popping, you get the left one first for each level
- push(root->right) & push(root->left) in the stack using if statements

```c++
class Solution {
public:

    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty() && root != NULL){
            root = st.top();
            st.pop();

            ans.push_back(root->val);

            // in the stack: push right first, and then left first
            // so while popping, left goes first and then right  
            if(root->right){
                st.push(root->right);
            }

            if(root->left){
                st.push(root->left);
            }
        }

        return ans;        
    }
};
```

# Postoroder traversal
- logic: LRN
- so we need to push the node at the end, but reversal is needed
- so first push the node, then do left, right 
- by doing this, we are following this order: NLR
- but stack in NRL
- so when we do reversal, we get LRN

```c++
class Solution {
public:
    vector<int> res;

    vector<int> postorderTraversal(TreeNode* root) {
        // using iterative now
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> s1;
        s1.push(root);

        while(!s1.empty()){
            TreeNode* t = s1.top();
            s1.pop();
            res.push_back(t->val);
            
            if(t->left) s1.push(t->left);
            if(t->right) s1.push(t->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

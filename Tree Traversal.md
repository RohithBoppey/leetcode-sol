## Iterative DFS Inorder Solution: 
    
```c++
class Solution {
public:
    vector<int> ans; // Store the in-order traversal result

    vector<int> inorderTraversal_Iterative(TreeNode* root) {
        
        stack<TreeNode*> st; 
        TreeNode* curr = root; 

        while (!st.empty() || curr != NULL) {
            // Traverse to the leftmost node
            while (curr != NULL) {
                st.push(curr); 
                curr = curr->left; 
            }

            // Visit the node
            curr = st.top(); 
            st.pop(); 
            ans.push_back(curr->val); 

            // Traverse the right subtree
            curr = curr->right;
        }

        return ans;
    }
};
```

## Iterative DFS Preorder Solution: 
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

## Iterative DFS Postorder Solution: 
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

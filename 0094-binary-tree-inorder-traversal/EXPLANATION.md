Keep going left until you are end of the loop

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

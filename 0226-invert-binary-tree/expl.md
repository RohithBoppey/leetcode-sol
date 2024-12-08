Simple recursion solution: 

In the each step -> first flip the left and right of the tree by a recursive call
and in the final step -> reverse them

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        if(root->left == NULL && root->right == NULL){
            // single node
            return root;
        }

        // interchange left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
    }
};
```​

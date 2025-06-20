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
    int solve(TreeNode* root){
        if(root == NULL){
            // depth is 0
            return 0;
        }

        // at any node, it is always 1 + max(left, right)
        int ld = solve(root->left);
        int rd = solve(root->right);
        return 1 + max(ld, rd);
    }

    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};
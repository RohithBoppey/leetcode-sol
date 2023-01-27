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
    bool solve(TreeNode* root, TreeNode* mx, TreeNode* mn){
        if(root == NULL){
            return true;
        }
        if((mx != NULL && mx->val >= root->val) || (mn != NULL && mn->val <= root->val)){
            return false;
        }
        return solve(root->left, mx, root) && solve(root->right, root, mn);
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
}; 
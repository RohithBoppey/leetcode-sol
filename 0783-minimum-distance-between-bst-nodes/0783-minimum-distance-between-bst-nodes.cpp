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
    int parent = -1;
    void solve(TreeNode* root, int& res){
        if(root == NULL){
            return;
        }
        solve(root->left, res);
        if(parent != -1){
            res = min(res, abs(root->val - parent));
        }
        parent = root->val;
        solve(root->right, res);
    }
    
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        solve(root, res);
        return res;
    }
};
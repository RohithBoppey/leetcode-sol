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
    // using DFS to solve the problem
    int ans;
    void solve(TreeNode* root, int val, int start){

        if(root->left == NULL && root->right == NULL){
            // reached a leaf node
            ans += val;
            return;
        }

        if(root->left){
            // take value from left
            solve(root->left, (val << 1) + root->left->val, 0); 
        }


        if(root->right){
            // take value from left
            solve(root->right, (val << 1) + root->right->val, 0); 
        }
        // solve(root->left, val, 0);
        // solve(root->right, val, 0);

    }

    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        int start = 0;
        solve(root, root->val, start);
        return ans;
    }
};
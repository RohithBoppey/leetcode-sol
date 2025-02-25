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
    vector<int> ans;

    // inorder traversal from the root level
    // Left Node Right - traversal
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        // solving using extra space
        ans.resize(0);
        solve(root);

        // ans is populated with the inorder traversal, ascending order
        int mn = INT_MAX;
        for(int i = 1; i < ans.size(); i++){
            mn = min(mn, ans[i] - ans[i - 1]);
        }

        return mn;
    }
};
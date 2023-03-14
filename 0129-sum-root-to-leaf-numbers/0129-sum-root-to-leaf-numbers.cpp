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
    void solve(TreeNode* root, string curr, int& ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans += stoi(curr + to_string(root->val));
            return;
        }
        solve(root->left, curr + to_string(root->val), ans);
        solve(root->right, curr + to_string(root->val), ans);
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        int ans = 0;
        string curr = "";
        solve(root, curr, ans);
        return ans;
    }
};
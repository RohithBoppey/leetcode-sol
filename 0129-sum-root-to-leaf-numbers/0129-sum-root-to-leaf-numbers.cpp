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
    void solve(TreeNode* root, string& curr, int& ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
//             we are including the last term
//             this is the root case
//             hence we need to add that
            ans += stoi(curr + to_string(root->val));
            return;
        }
//         with reference, we are subtracting that amount of length from the curr generated so far
        string s = to_string(root->val);
        curr += s;
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
//         removing the last s elements
        curr = curr.substr(0, curr.length() - s.length());
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
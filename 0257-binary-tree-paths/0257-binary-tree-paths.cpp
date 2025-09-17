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
    vector<string> ans;
    string curr;

    void solve(TreeNode* root) {
        if (!root) return;

        int before = curr.size();          // remember state
        curr += to_string(root->val);      // add current value

        if (!root->left && !root->right) { // leaf
            ans.push_back(curr);
        } else {
            curr += "->";
            solve(root->left);
            solve(root->right);
        }

        curr.resize(before);  // rollback to old state
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root); 
        curr = "";
        return ans; 
    }
};
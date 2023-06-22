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

    void solve(TreeNode* root, int dir, int steps, int& ans){
        // if it the path exists, then 1 step added, else reset
        if(root == NULL){
            return;
        }

        ans = max(ans, steps);

        if(dir == 0){
            // move left
            solve(root->left, 1, steps + 1, ans);
            solve(root->right, 0, 1, ans);
        }else{
            // should move right 
            solve(root->right, 0, 1 + steps, ans);
            solve(root->left, 1, 1, ans);
        }
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;

        // from the start, can go left or right
        // 0 for left, 1 for right
        solve(root, 0, 0, ans);
        solve(root, 1, 0, ans);

        return ans;
    }
};
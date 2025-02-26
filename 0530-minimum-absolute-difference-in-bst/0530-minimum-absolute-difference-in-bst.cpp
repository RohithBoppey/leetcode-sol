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

    int mind;
    // using inorder to get the sorted order, but in each step, we require to remember the parent, so that we get the min difference
    // in the left process (at the end, parent gets updated for the visit process), in the visit process, do the difference, and modify the parent to this node for the right subtree to remember this
    // passing it as reference because the subtree should change this value
    void solve(TreeNode* root, TreeNode*& prev){
        if(root == NULL){
            return;
        }
        // solve the left subtreee
        solve(root->left, prev);
        // since left changes the parent
        if(prev != NULL){
            mind = min(mind, abs(prev->val - root->val));
        }

        // change the parent for the right subtree
        prev = root;

        solve(root->right, prev);

    }

    int getMinimumDifference(TreeNode* root) {
        mind = INT_MAX;
        TreeNode* prev = NULL;
        solve(root, prev);
        return mind;
    }
};
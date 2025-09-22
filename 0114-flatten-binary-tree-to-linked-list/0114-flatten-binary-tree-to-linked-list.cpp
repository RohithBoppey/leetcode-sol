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
    TreeNode* prev;

    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        TreeNode* right = root->right;

        if(prev){
            // not the first node at this point, so make the current tree processed being as root;
            prev->right = root;
            prev->left = NULL;
        }

        // for the next subtree
        prev = root;
        
        // since this is asking pre-order traversal
        flatten(root->left);
        flatten(right);

    }
};
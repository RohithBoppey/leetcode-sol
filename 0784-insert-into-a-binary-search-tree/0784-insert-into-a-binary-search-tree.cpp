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

    TreeNode* insert(TreeNode* root, int val){
        if(root == NULL){
            return new TreeNode(val);
        }
        // root can never be NULL
        // root can have >= 1 element
        int rv = root->val;

        if(rv < val){
            // insert at the right
            root->right = insert(root->right, val);
        }else{
            root->left = insert(root->left, val);
        }

        return root;
    } 

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, val);
    }
};
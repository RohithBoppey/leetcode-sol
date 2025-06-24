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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }

        // go find the the node until you find the node
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        } else{
            // found the node
            // now check for each conditions
            if(!root->left && !root->right){
                // meaning single node
                return NULL; 
            }
            // now either of the nodes can be NULL
            // one of them is null
            if(!root->left || !root->right){
                return (root->left) ? root->left : root->right; 
            }

            // if reached this point, that means you are deleting a node with both the values
            // so choose the left most value in the right subtree, or else right most value in the left subtree
            TreeNode* t = root->left; 
            while(t->right != NULL) t = t->right; 

            // node is found
            root->val = t->val; 
            root->left = deleteNode(root->left, t->val);
        }

        return root; 
    }
};
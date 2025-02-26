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

    bool solve(TreeNode* root, long l, long h){

        if(root == NULL){
            return true;
        }

        cout << root->val << endl;

        long val = root->val;
        // check if the selected node is under limits or not
        int valid = (val >= l && val <= h);
        if(!valid){
            // not present in limits
            return false;
        }

        // the node itself is valid
        // check for left and right
        
        if(!solve(root->left, l, val - 1)){
            return false;
        }


        if(!solve(root->right, val + 1, h)){
            return false;
        }

        return true;

    }

    bool isValidBST(TreeNode* root) {
        
        // set limits for a certain node appraoch
        long low = INT_MIN, high = INT_MAX;
        
        // if there is a single node, allow it
        if(!root->left && !root->right){
            // singe node
            return true;
        }

        return solve(root, low, high);

    }
};
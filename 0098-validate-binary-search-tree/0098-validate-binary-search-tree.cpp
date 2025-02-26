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

    bool solve(TreeNode* root, long& l, long& h){

        if(root == NULL){
            return true;
        }

        long val = root->val;
        // check if the selected node is under limits or not
        int valid = (val >= l && val <= h);
        if(!valid){
            // not present in limits
            return false;
        }

        // the node itself is valid
        // check for left and right
        int temp = h;
        h = val - 1;

        if(!solve(root->left, l, h)){
            return false;
        }
        h = temp;

        temp = l;
        l = val + 1;
        if(!solve(root->right, l, h)){
            return false;
        }
        l = temp;

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
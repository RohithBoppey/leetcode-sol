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

    unordered_map<TreeNode*, int> mp;

    // return the max amount that can be stolen from a given current node
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        if(mp.find(root) != mp.end()){
            // alraedy exists
            return mp[root];
        }

        // at any point, he can rob the current node + grandchildren || both the children
        int take, notTake; 

        // take
        int l1 = (root->left && root->left->left) ? solve(root->left->left) : 0;
        int l2 = (root->left && root->left->right) ? solve(root->left->right) : 0;
        int r1 = (root->right && root->right->left) ? solve(root->right->left) : 0;
        int r2 = (root->right && root->right->right) ? solve(root->right->right) : 0;

        // if robbing
        take = root->val + l1 + l2 + r1 + r2;

        // if not taking, rob both the children
        int c1 = (root->left) ? solve(root->left) : 0;
        int c2 = (root->right) ? solve(root->right) : 0;

        notTake = c1 + c2; 

        return mp[root] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        return solve(root);   
    }
};
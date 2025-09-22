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
    int curr = INT_MIN;
    int md = 0, mxd = 1; // count of the mode, max mode seen so far
    vector<int> ans; 

    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        solve(root->left);

        // check if this is mode or not
        if(curr != root->val){
            curr = root->val;
            md = 1;
        }else{
            md++;
        }

        // now calc mode
        if(md > mxd){
            mxd = md;
            ans.clear();
            ans.push_back(root->val);
        }else if(md == mxd){
            // this is also a mode
            ans.push_back(root->val);
        }

        solve(root->right);

    }

    vector<int> findMode(TreeNode* root) {
        solve(root);
        return ans;
    }
};
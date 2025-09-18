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

    string ans, curr; 

    void solve(TreeNode* root){

        // add the string
        char ch = root->val + 'a';
        // cout << ch << endl;
        curr = ch + curr;

        if(root->left == NULL && root->right == NULL){
            // reached leaf node
            if(ans == "" || curr < ans) ans = curr; 
        }

        // do left and right
        if (root->left) solve(root->left);
        if (root->right) solve(root->right);

        // remove the added letter in curr
        curr = curr.substr(1); 
    }

    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        curr = "";
        solve(root);
        return ans; 
    }
};
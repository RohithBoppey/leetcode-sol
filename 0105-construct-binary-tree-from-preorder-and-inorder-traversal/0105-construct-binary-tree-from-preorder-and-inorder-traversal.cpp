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
    TreeNode* solve(vector<int>& pre, int s1, int e1, vector<int>& inor, int s2, int e2){
        if(s1 > e1 || s2 > e2){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[s1]);
        int in = s2;
        while(root->val != inor[in]){
            in++;
        }
        root->left = solve(pre, s1 + 1, s1 + in - s2, inor, s2, in - 1);
        root->right = solve(pre, s1 + in - s2 + 1, e1, inor, in + 1, e2);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
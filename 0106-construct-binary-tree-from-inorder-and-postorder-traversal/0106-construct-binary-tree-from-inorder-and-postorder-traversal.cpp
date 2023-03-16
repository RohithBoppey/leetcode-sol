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
    TreeNode* solve(vector<int>& in, int x, int y, vector<int>& post, int a, int b){
        if(x > y || a > b){
            return NULL;
        }
        TreeNode* node = new TreeNode(post[b]);
        int ind = x;
        while(node->val != in[ind]){
            ind++;
        }
//         partition
        node->left = solve(in, x, ind - 1, post, a, a + ind - x - 1);
        node->right = solve(in, ind + 1, y, post, a + ind - x, b - 1);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
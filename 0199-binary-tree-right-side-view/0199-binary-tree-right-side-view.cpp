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
    // vector<vector<int>> bst;
    vector<int> curr; 
    vector<int> ans; 

    void BST(TreeNode* root){
        if(root == NULL){
            return;
        }

        queue<TreeNode*> q; // to store the pointers
        
        // first level
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();

            if(t == NULL){
                // reached the end of the level
                ans.push_back(curr[curr.size() - 1]);
                curr.resize(0, 0);
                
                // but the next level can be there
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                // still in the same level
                curr.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        BST(root);
        return ans; 
    }
};
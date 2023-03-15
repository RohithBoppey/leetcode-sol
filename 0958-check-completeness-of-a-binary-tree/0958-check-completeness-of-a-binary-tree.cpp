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
    bool isCompleteTree(TreeNode* root) {
//         the idea is to find a logic like
//         iterate until first null is not found using bfs
//         after first node is found
//         iterate the rest until next null is not found
//         if found; false, else true
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);    
            }else{
                break;
            }
        }
        
//         null is found here
        while(!q.empty()){
            if(q.front() == NULL){
                q.pop();
            }else{
                return false;
            }
        }
        
        return true;
    }
};



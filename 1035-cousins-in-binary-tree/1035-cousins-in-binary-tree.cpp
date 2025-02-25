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
    bool isCousins(TreeNode* root, int x, int y) {
        // trying to skip the level information
        // but still require parent and node information

        queue<TreeNode*> q;
        q.push(root);
        
        // using the level wise operation logic 
        TreeNode* node;

        // check whether the values are present or not

        while(!q.empty()){
            // find the number of nodes to process
            // this eliminates the need for parent
            int isA = false, isB = false;
            int n = q.size();
            // check if both exist in the same level or not
            while(n--){
                auto node = q.front();
                q.pop();

                // check whether the A and B is present or not
                // they can be present in different levels as well
                isA = (node->val == x) ? true : isA;
                isB = (node->val == y) ? true : isB;

                // can check if they are siblings or not
                // meaning they have the same parent
                if(node->left != NULL && node->right != NULL){
                    if(
                        node->left->val == x && node->right->val == y
                        || 
                        node->right->val == x && node->left->val == y
                        ){
                        // they are siblings
                        return false;
                    }
                }

                // push the left and right nodes
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            // if both are present
            if (isA && isB){
                return true;
            }

        }

        return false;
    }
};
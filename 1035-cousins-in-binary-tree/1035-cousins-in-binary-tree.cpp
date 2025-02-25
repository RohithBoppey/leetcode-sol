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
        // making seperate variables for both x and y & when both are done, break the loop
        // x
        int xp, xl = -1;
        // y
        int yp, yl = -1;

        // level, value & parent
        queue<pair<int, pair<TreeNode*, int>>> q;

        q.push({1, {root, -1}});

        int l, p;
        TreeNode* node; 

        while(!q.empty()){
            
            auto t = q.front();
            q.pop();

            l = t.first;
            node = t.second.first;
            p = t.second.second;

            // if it matches our target, compare
            if(node->val == x){
                xl = l;
                xp = p;
            }

            if(node->val == y){
                yl = l;
                yp = p;
            }

            if(xl != -1 && yl != -1){
                // both variables are found
                // can break the while loop
                break;
            }

            // push the left and right nodes
            if(node->left){
                q.push({l + 1, {node->left, node->val}});
            }
            if(node->right){
                q.push({l + 1, {node->right, node->val}});
            }
        }

        return (xl == yl) && (yp != xp);
    }
};
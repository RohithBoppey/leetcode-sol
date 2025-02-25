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

        queue<pair<TreeNode*,int>> q;
        q.push({root, -1});
        
        // using the level wise operation logic 
        TreeNode* node;
        int parent;

        int xp = -1, xl, yp = -1, yl;
        int i = 0;
        
        while(!q.empty()){
            // find the number of nodes to process
            int n = q.size();
            while(n--){
                auto f = q.front();
                q.pop();
                node = f.first;
                parent = f.second;

                if(node->val == x){
                    xp = parent;
                    xl = i;
                }
                if(node->val == y){
                    yp = parent;
                    yl = i;
                }

                if(xp != -1 && yp != -1){
                    // both are found
                    break;
                }

                // push the left and right nodes
                if(node->left){
                    q.push({node->left, node->val});
                }
                if(node->right){
                    q.push({node->right, node->val});
                }
            }
            i++;
        }

        cout << xp << xl << yp << yl;
        return (xp != yp) && (xl == yl);


    }
};
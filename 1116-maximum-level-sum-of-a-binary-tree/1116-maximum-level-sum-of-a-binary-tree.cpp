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

    int ans; 
    int x; 
    int lx;

    void bfs(TreeNode* root){
        if(root == NULL){
            return; 
        }
        
        queue<TreeNode*> q; 
        q.push(root);
        q.push(NULL);

        int lsum = 0;
        lx = 1;

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            if(t == NULL){
                if(lsum > ans){
                    lx = x;
                    ans = lsum;
                }

                lsum = 0;

                if(!q.empty()){
                    q.push(NULL);
                }

                x++;
            }else{
                // t is not null
                // push children
                lsum += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);

            }

        }

    }

    int maxLevelSum(TreeNode* root) {
        ans = INT_MIN;
        x = 1; 
        lx = 1;
        bfs(root);
        return lx; 
    }
};
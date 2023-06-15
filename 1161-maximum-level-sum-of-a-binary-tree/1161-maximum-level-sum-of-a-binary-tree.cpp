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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int sum = INT_MIN, level_sum = 0, level = 1;
        
        // using bfs
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 1});
        q.push({NULL, 1});
        
        TreeNode* node;
        int l;
        
        while(!q.empty()){
            pair<TreeNode*, int> f = q.front();
            q.pop();
            
            node = f.first;
            l = f.second;    
            
            
            if(node == NULL){
                if(sum < level_sum){
                    sum = level_sum;
                    level = l;
                }
                level_sum = 0;
                if(!q.empty()){
                    // some elements exists
                    q.push({NULL, l + 1});
                }
            }else{
                // not null, some value present
  
                level_sum += node->val;
                if(node->left != NULL){
                    q.push({node->left, l + 1});
                }
                if(node->right != NULL){
                    q.push({node->right, l + 1});
                }
            }
        }
            
        return level;
    }
};
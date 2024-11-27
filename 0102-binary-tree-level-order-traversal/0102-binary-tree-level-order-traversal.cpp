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
    
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) {return ans;}
        
        vector<int> currV;
        int currLevel = 0;
        
        queue<
            pair<
            TreeNode*,
            int
            >
                > q;
        
        pair<TreeNode*, int> p;
        
        q.push({root, 0});
        
        while(!q.empty()){
            
            // find out the current level and push if needed
            p = q.front();
            
            if(p.second > currLevel){
                // level ended
                ans.push_back(currV);
                currV = vector<int>();
                currLevel = p.second;
            }
            
            TreeNode* node = p.first; 
            currV.push_back(node->val);
            
            // push left and right if needed
            if(node->left){
                q.push({node->left, p.second + 1});
            }
            
            if (node->right){
                q.push({node->right, p.second + 1});
            }
            
            q.pop();
        }
        
        // last you have one pair left
        ans.push_back(currV);
        
        return ans;
    }
};
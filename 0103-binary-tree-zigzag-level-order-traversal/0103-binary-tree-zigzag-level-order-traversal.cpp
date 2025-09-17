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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL){
            return ans; 
        }

        queue<TreeNode*> q; 
        q.push(root);
        q.push(NULL);

        int flag = 0;

        deque<int> curr; 

        while(!q.empty()){
            TreeNode* t = q.front(); 
            q.pop();

            if(t == NULL){
                ans.push_back(vector<int>(curr.begin(), curr.end()));
                curr.clear(); 

                if(!q.empty()){
                    // not the last level
                    q.push(NULL);
                }

                flag = !flag;

            }else{
                if(flag == 1){
                    // right to left
                    curr.push_front(t->val);
                }else{
                    curr.push_back(t->val);
                }

                // push the next children
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            
            }
        }

        return ans; 
    }
};
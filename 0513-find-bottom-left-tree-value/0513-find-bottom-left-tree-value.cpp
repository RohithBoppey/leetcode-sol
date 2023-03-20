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
    // vector<vector<int>> bfs;
    vector<int> curr;
    void print2dVector(vector<vector<int>> v){
        for(auto x: v){
            for(auto y: x){
                cout << y << " ";
            }
            cout << "" << endl;
        }
    }

    void solve(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
//                 level is ending
                // bfs.push_back(curr);
                curr.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
//                 not null
                curr.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);        
                }
            }
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        solve(root);
        // print2dVector(bfs);
        return curr[0];
        // return 0;
    }
};
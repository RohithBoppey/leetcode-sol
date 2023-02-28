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
//     global variables
    unordered_map<string, vector<TreeNode*>> mp;
    vector<TreeNode*> res;
    string valueString = "";
    
    string compareDFS(TreeNode* root){
        if(root == NULL){
            return "";
        }
        valueString = "(" + compareDFS(root->left) + to_string(root->val) + compareDFS(root->right) + ")";
        mp[valueString].push_back(root);
        return valueString;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         the idea is to memoize the calls
        compareDFS(root);
        for(auto &it: mp){
            if(it.second.size() > 1){
                res.push_back(it.second[0]);
            }
        }
        return res;
    }
};
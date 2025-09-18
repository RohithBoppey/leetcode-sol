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
    vector<int> ans; 
    int curr;
    int max_count = 0;
    int curr_count = 0; 

    void solve(int val){
        if(val != curr){
            // now going with a new variable, since all the previous variables are done
            curr = val;
            curr_count = 0; 
        }

        curr_count++;

        if(curr_count > max_count){
            // first new max found
            max_count = curr_count; 
            ans.clear();
            ans.push_back(curr);
        }else if(curr_count == max_count){
            // already a max is present, new one came
            ans.push_back(curr);
        }

    }

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        // handle current value count
        solve(root->val);
        inorder(root->right);

    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans; 
    }
};
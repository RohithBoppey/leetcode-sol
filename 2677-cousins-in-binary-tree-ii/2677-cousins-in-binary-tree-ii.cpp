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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // single pass solution

        queue<TreeNode*> q;
        q.push(root);
        int levelSum = root->val, nextLevelSum = 0;
        TreeNode* curr;

        while(!q.empty()){
            // using level wise logic
            int n = q.size();
            // processing level wise
            nextLevelSum = 0;
            
            while(n--){
                curr = q.front();
                q.pop();

                // replace a node's value with the sibling sum (from the parent level itself)
                int siblingSum = 0;
                siblingSum += curr->left ? curr->left->val : 0; 
                siblingSum += curr->right ? curr->right->val : 0; 

                // modify the nodes with levelSum and siblingSum (now this is the node's value only)
                curr->val = levelSum - curr->val;

                // while pushing, modify the node value to siblingSum 
                // and calculate for the next level
                if(curr->left){
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    q.push(curr->right);
                }
            }

            // now the next level sum is populated,
            // replace with the existing levelSum for the next iteration
            levelSum = nextLevelSum;
        }

        return root;

    }
};
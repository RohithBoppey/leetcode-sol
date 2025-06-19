- the logic for this is: L, N, R
- so for any node, we need to find the left most node, hence starting from root, curr = root, we are pushing all the nodes into the stack by going left.
- once all the nodes are pushed, that means first left tree is done
- hence pop the element, put it in the array, now check if there is any right tree
- if yes, you can move to right subtree as you are currently at the left (almost leaf node), so do curr = curr->right

Keep going left until you are end of the loop

```c++
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
    
    // inorder traversal -> 
    // left most
    // curr
    // right most
    
    vector<int> ans;
    
    void helper(TreeNode* curr){
        if(curr == NULL){
            return;
        }
        
        helper(curr->left);
        ans.push_back(curr->val);
        helper(curr->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};
```

Before going into the left or right level -> do the modifications in the parent stage itself, just like in [Cousins in a binary Tree](https://leetcode.com/problems/cousins-in-binary-tree-ii/description/)

In this case, while going into next step => doing * 2 or << 1 is a must -> but add number based on left or right value
- why are we changing in place only? So that during execution, at a certain node, we already will have the modified value!! This is an **important concept**

```c++
class Solution {
public:
    // using DFS to solve the problem
    int ans;
    void solve(TreeNode* root, int val, int start){

        if(root->left == NULL && root->right == NULL){
            // reached a leaf node
            ans += val;
            return;
        }

        if(root->left){
            // take value from left
            solve(root->left, (val << 1) + root->left->val, 0); 
        }


        if(root->right){
            // take value from right
            solve(root->right, (val << 1) + root->right->val); 
        }
       
    }

    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        solve(root, root->val);
        return ans;
    }
};
```

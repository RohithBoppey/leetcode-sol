- so for preorder traversal (NLR), we need to completely discard the right branch, put the left branch in place right?
- so first step is isolating right branch
- now if you already have a prev pointer for tracking until where we have done the flattening, then we proceed from there
- so if(prev) then prev->right = current_node and prev->left = NULL
- but if prev not there, then that is the first root right? so either way, we should always update the prev to be our current root (current_node), hence the current_logic
```c+
        if(prev){
            // put the current node to the right
            prev->right = root;
            prev->left = NULL;
        }
```
- now left to solve left and right so solve(root->left) and solve(right) 


```c++
class Solution {
public:
    TreeNode* prev; 

    void flatten(TreeNode* root) {
        if(root == NULL){
            return; 
        }

        // overwriting right
        TreeNode* right = root->right; 

        if(prev){
            // put the current node to the right
            prev->right = root;
            prev->left = NULL;
        }

        prev = root; 

        flatten(prev->left);
        flatten(right);

    }
};
```

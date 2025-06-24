- deletion should happen based on different conditions
- first find the node where it exists using the simple search logic
- once the node is found, then based on the below conditions, do the deletion logic
- if it is a leaf node, then directly return NULL
- if it is a single child node, then return the not null node
- if it is having both children, then you should find the **left tree right most value** or else **right tree left most value**, then replace it properly.
- now after replacing the value, delete the new node using `root->left = deleteNode(root->left, t->val)`

```c++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }

        // go find the the node until you find the node
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        } else{
            // found the node
            // now check for each conditions
            if(!root->left && !root->right){
                // meaning single node
                return NULL; 
            }
            // now either of the nodes can be NULL
            // one of them is null
            if(!root->left || !root->right){
                return (root->left) ? root->left : root->right; 
            }

            // if reached this point, that means you are deleting a node with both the values
            // so choose the left most value in the right subtree, or else right most value in the left subtree
            TreeNode* t = root->left; 
            while(t->right != NULL) t = t->right; 

            // node is found
            root->val = t->val; 
            root->left = deleteNode(root->left, t->val);
        }

        return root; 
    }
};
```

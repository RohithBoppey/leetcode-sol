Self got solution: 
Working, but not be the most optimized one I believe: 

Idea: 
- each node you see should be under some limits
- the root node can be under INT_MIN and INT_MAX
- so when going to the left, the limits for the left node can be: [l, val - 1]
- when right, limits: [val + 1, h]
- using this logic -> the sequence would be: if not under limits => false ; if left not a subtree => false ; if right not a subtree => false ; now is a proper BST => return true

```c++
class Solution {
public:

    bool solve(TreeNode* root, long& l, long& h){

        if(root == NULL){
            return true;
        }

        cout << root->val << endl;

        long val = root->val;
        // check if the selected node is under limits or not
        int valid = (val >= l && val <= h);
        if(!valid){
            // not present in limits
            return false;
        }

        // the node itself is valid
        // check for left and right
        int temp = h;
        h = val - 1;

        if(!solve(root->left, l, h)){
            return false;
        }
        h = temp;

        temp = l;
        l = val + 1;
        if(!solve(root->right, l, h)){
            return false;
        }
        l = temp;

        return true;

    }

    bool isValidBST(TreeNode* root) {
        
        // set limits for a certain node appraoch
        long low = INT_MIN, high = INT_MAX;
        
        // if there is a single node, allow it
        if(!root->left && !root->right){
            // singe node
            return true;
        }

        return solve(root, low, high);

    }
};
```

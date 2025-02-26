With extra space: 
```c++
class Solution {
public:
    vector<int> ans;

    // inorder traversal from the root level
    // Left Node Right - traversal
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        // solving using extra space
        ans.resize(0);
        solve(root);

        // ans is populated with the inorder traversal, ascending order
        int mn = INT_MAX;
        for(int i = 1; i < ans.size(); i++){
            mn = min(mn, ans[i] - ans[i - 1]);
        }

        return mn;
    }
};
```

Inorder modification + **critical concept in backtracking trees**
![WhatsApp Image 2025-02-26 at 09 51 05_0829306a](https://github.com/user-attachments/assets/80107de0-adf0-4afa-9cd2-b4a8dfb9bdc3)

```c++
class Solution {
public:

    int mind;
    // using inorder to get the sorted order, but in each step, we require to remember the parent, so that we get the min difference
    // in the left process (at the end, parent gets updated for the visit process), in the visit process, do the difference, and modify the parent to this node for the right subtree to remember this
    // passing it as reference because the subtree should change this value
    void solve(TreeNode* root, TreeNode*& prev){
        if(root == NULL){
            return;
        }
        // solve the left subtreee
        solve(root->left, prev);
        // since left changes the parent
        if(prev != NULL){
            mind = min(mind, abs(prev->val - root->val));
        }

        // change the parent for the right subtree
        prev = root;

        solve(root->right, prev);

    }

    int getMinimumDifference(TreeNode* root) {
        mind = INT_MAX;
        TreeNode* prev = NULL;
        solve(root, prev);
        return mind;
    }
};
```




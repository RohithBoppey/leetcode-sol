- optimized and standard solution
- instead of computing grandchildren, compute like this: at each node, what is the max value if I rob this node or not rob this node
- so that way I can bring the left and right subtree values
- take would be: if I take this node, then I must ignore the children, so `root->val + left.second + right.second`
- and for not taking: if I do not take this node, then I can rob the children node or even ignore them, and the left and right subtrees are independant of each other, hence I can either rob left or right or both, hence handling it using 2 max

```c++
class Solution {
public:
    // at any point, we can rob or not robb
    // pair of max of robbing, not robbing
    pair<int, int> solve(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        
        // get values of left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        // now just compare and return max
        // if taking, we should not take subtree part
        int take = root->val + left.second + right.second; 
        // if not taking, we can either rob the children or not rob them
        int notTake = max(left.first, left.second) + max(right.first, right.second);

        return {take, notTake};
    }

    int rob(TreeNode* root) {
        pair<int, int> p = solve(root);
        return max(p.first, p.second);   
    }
};
```


- my approach
- slightly takes longer because of recursion and memoization
- at any point, we can rob a node or not rob
- if we are robbing, we can rob the grandchildren, so calculating the values
- if we are not robbing, we can rob both the children now

```c++
class Solution {
public:

    unordered_map<TreeNode*, int> mp;

    // return the max amount that can be stolen from a given current node
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        if(mp.find(root) != mp.end()){
            // alraedy exists
            return mp[root];
        }

        // at any point, he can rob the current node + grandchildren || both the children
        int take, notTake; 

        // take
        int l1 = (root->left && root->left->left) ? solve(root->left->left) : 0;
        int l2 = (root->left && root->left->right) ? solve(root->left->right) : 0;
        int r1 = (root->right && root->right->left) ? solve(root->right->left) : 0;
        int r2 = (root->right && root->right->right) ? solve(root->right->right) : 0;

        // if robbing
        take = root->val + l1 + l2 + r1 + r2;

        // if not taking, rob both the children
        int c1 = (root->left) ? solve(root->left) : 0;
        int c2 = (root->right) ? solve(root->right) : 0;

        notTake = c1 + c2; 

        return mp[root] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        return solve(root);   
    }
};
```

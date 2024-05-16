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
class Solution
{
public:
    // i want to have a function
    // takes in left result, right result
    // already have the operation in middle
    // so takes these 3 and returns the result

    // this function should only activate when we want to return result
    bool solve(int left, int right, int op)
    {
        if (op == 2)
        {
            return left || right;
        }
        if (op == 3)
        {
            return left && right;
        }
        return 0;
    }

    bool evaluateTree(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            // only element
            // return what is there on value
            return root->val;
        }

        int left = evaluateTree(root->left);
        int right = evaluateTree(root->right);

        return solve(left, right, root->val);
    }
};
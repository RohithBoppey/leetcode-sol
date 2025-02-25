Using 2 passes: One to find the levelWiseSum and next one to modify
![WhatsApp Image 2025-02-25 at 23 24 30_ba328e5b](https://github.com/user-attachments/assets/1d583669-6a5e-41f8-b6a3-96b3c41a3321)
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        // need level wise sum for this problem
        vector<int> levelWiseSum;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* curr;

        // 1. Level wise sum is required
        while(!q.empty()){
            // using the level wise operation logic
            // n represents number of nodes in this level
            int n = q.size();
            int sum = 0;
            while(n--){
                curr = q.front();
                q.pop();
                
                sum += curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            levelWiseSum.push_back(sum);
        }

        // 2. Modify the tree in place with the new sum
        q.push(root);
        
        // start from this level
        int i = 1;

        // modify the root explicitly
        root->val = 0;
        while(!q.empty()){
            // using the level wise operation logic
            // n represents number of nodes in this level
            int n = q.size();

            while(n--){
                curr = q.front();
                q.pop();
                
                // calculate sibling sum for the children;
                int siblingSum = 0;
                siblingSum += (curr->left) ? curr->left->val : 0;
                siblingSum += (curr->right) ? curr->right->val : 0;
               
                if(curr->left){
                    curr->left->val = levelWiseSum[i] - siblingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = levelWiseSum[i] - siblingSum;
                    q.push(curr->right);
                }
            }

            i++;
        }

        return root;
    }
};
```

Single pass, requires moodifying (not easy to understand) ❌        
![image](https://github.com/user-attachments/assets/bb0613bd-d035-464e-aa88-d62091f95a3f)        
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
```

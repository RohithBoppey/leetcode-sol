- solution without level values, but instead NULL pointers
- start with root, NULL in the queue
- for any value, add to curr, push left and right
- if NULL occured, 2 possibilites: one is all the traversal is done, else one level wise traversal is done
- how to check this level is done? if q is not empty, so we need to push another NULL at the end in this case
- if q empty(), meaning this is the last value in the tree, so need not do anything

```c++
class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans; 

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        queue<TreeNode*> q; // to store the pointers
        
        // first level
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();

            if(t == NULL){
                // reached the end of the level
                ans.push_back(curr);
                curr.resize(0, 0);

                // but the next level can be there
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                // still in the same level
                curr.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }

        return ans;
    }
};
```

Simple solution only using no NULL pointers, but instead level!

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
    
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) {return ans;}
        
        vector<int> currV;
        int currLevel = 0;
        
        queue<
            pair<
            TreeNode*,
            int
            >
                > q;
        
        pair<TreeNode*, int> p;
        
        q.push({root, 0});
        
        while(!q.empty()){
            
            // find out the current level and push if needed
            p = q.front();
            
            if(p.second > currLevel){
                // level ended
                ans.push_back(currV);
                currV = vector<int>();
                currLevel = p.second;
            }
            
            TreeNode* node = p.first; 
            currV.push_back(node->val);
            
            // push left and right if needed
            if(node->left){
                q.push({node->left, p.second + 1});
            }
            
            if (node->right){
                q.push({node->right, p.second + 1});
            }
            
            q.pop();
        }
        
        // last you have one pair left
        ans.push_back(currV);
        
        return ans;
    }
};
```

My Solution:
- Explicitly in BFS -> check whether the value x and y exists or not, and then if it exists, put it aside.
- When both are found, break the DFS -> compare parent and level for both.
  
```c++
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        // making seperate variables for both x and y & when both are done, break the loop
        // x
        int xp, xl = -1;
        // y
        int yp, yl = -1;

        // level, value & parent
        queue<pair<int, pair<TreeNode*, int>>> q;

        q.push({1, {root, -1}});

        int l, p;
        TreeNode* node; 

        while(!q.empty()){
            
            auto t = q.front();
            q.pop();

            l = t.first;
            node = t.second.first;
            p = t.second.second;

            // if it matches our target, compare
            if(node->val == x){
                xl = l;
                xp = p;
            }

            if(node->val == y){
                yl = l;
                yp = p;
            }

            if(xl != -1 && yl != -1){
                // both variables are found
                // can break the while loop
                break;
            }

            // push the left and right nodes
            if(node->left){
                q.push({l + 1, {node->left, node->val}});
            }
            if(node->right){
                q.push({l + 1, {node->right, node->val}});
            }
        }

        return (xl == yl) && (yp != xp);
    }
};
```

Slighly better solution because this uses the logic for BT: 
Compeltely remove the level dependency inside the pair, put it outside and handle using the `queue size == number of nodes in that level` logic.
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
    bool isCousins(TreeNode* root, int x, int y) {
        // trying to skip the level information
        // but still require parent and node information

        queue<pair<TreeNode*,int>> q;
        q.push({root, -1});
        
        // using the level wise operation logic 
        TreeNode* node;
        int parent;

        int xp = -1, xl, yp = -1, yl;
        int i = 0;
        
        while(!q.empty()){
            // find the number of nodes to process
            int n = q.size();
            while(n--){
                auto f = q.front();
                q.pop();
                node = f.first;
                parent = f.second;

                if(node->val == x){
                    xp = parent;
                    xl = i;
                }
                if(node->val == y){
                    yp = parent;
                    yl = i;
                }

                if(xp != -1 && yp != -1){
                    // both are found
                    break;
                }

                // push the left and right nodes
                if(node->left){
                    q.push({node->left, node->val});
                }
                if(node->right){
                    q.push({node->right, node->val});
                }
            }
            i++;
        }

        cout << xp << xl << yp << yl;
        return (xp != yp) && (xl == yl);


    }
};
```

Optimal approach: 
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
    bool isCousins(TreeNode* root, int x, int y) {
        // trying to skip the level information
        // but still require parent and node information

        queue<TreeNode*> q;
        q.push(root);
        
        // using the level wise operation logic 
        TreeNode* node;

        // check whether the values are present or not

        while(!q.empty()){
            // find the number of nodes to process
            // this eliminates the need for parent
            int isA = false, isB = false;
            int n = q.size();
            // check if both exist in the same level or not
            while(n--){
                auto node = q.front();
                q.pop();

                // check whether the A and B is present or not
                // they can be present in different levels as well
                isA = (node->val == x) ? true : isA;
                isB = (node->val == y) ? true : isB;

                // can check if they are siblings or not
                // meaning they have the same parent
                if(node->left != NULL && node->right != NULL){
                    if(
                        node->left->val == x && node->right->val == y
                        || 
                        node->right->val == x && node->left->val == y
                        ){
                        // they are siblings
                        return false;
                    }
                }

                // push the left and right nodes
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            // if both are present
            if (isA && isB){
                return true;
            }

        }

        return false;
    }
};
```

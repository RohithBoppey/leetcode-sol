```c++
// DFS Helper to store top view nodes
void dfs(Node* node, int hd, int level, 
         map<int, pair<int, int>>& topNodes) {
  
    if (!node) return;

    // If horizontal distance is encountered for 
    // the first time or if it's at a higher level
    if (topNodes.find(hd) == topNodes.end() || 
        topNodes[hd].second > level) {
        topNodes[hd] = {node->data, level};
    }

    // Recur for left and right subtrees
    dfs(node->left, hd - 1, level + 1, topNodes);
    dfs(node->right, hd + 1, level + 1, topNodes);
}

// DFS Approach to find the top view of a binary tree
vector<int> topView(Node* root) {
    vector<int> result;
    if (!root) return result;
    
    // Horizontal distance -> {node's value, level}
    map<int, pair<int, int>> topNodes; 
    
    // Start DFS traversal
    dfs(root, 0, 0, topNodes);

    // Collect nodes from the map
    for (auto it : topNodes) {
        result.push_back(it.second.first);
    }

    return result;
}
```

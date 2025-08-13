## Top

```c++
// DFS helper for Top View
void dfsTop(Node* node, int hd, int level, map<int, pair<int, int>>& topNodes) {
    if (!node) return;

    // If hd is not present or current level is closer to root
    if (topNodes.find(hd) == topNodes.end() || topNodes[hd].second > level) {
        topNodes[hd] = {node->data, level};
    }

    // Go left (hd - 1) and right (hd + 1)
    dfsTop(node->left, hd - 1, level + 1, topNodes);
    dfsTop(node->right, hd + 1, level + 1, topNodes);
}

vector<int> topView(Node* root) {
    vector<int> result;
    if (!root) return result;

    map<int, pair<int, int>> topNodes; // hd → {value, level}
    dfsTop(root, 0, 0, topNodes);

    for (auto &it : topNodes) {
        result.push_back(it.second.first);
    }
    return result;
}

```

---

## Bottom

```c++
// DFS helper for Bottom View
void dfsBottom(Node* node, int hd, int level, map<int, pair<int, int>>& bottomNodes) {
    if (!node) return;

    // If hd is not present OR current level is deeper than stored level
    if (bottomNodes.find(hd) == bottomNodes.end() || bottomNodes[hd].second <= level) {
        bottomNodes[hd] = {node->data, level};
    }

    dfsBottom(node->left, hd - 1, level + 1, bottomNodes);
    dfsBottom(node->right, hd + 1, level + 1, bottomNodes);
}

vector<int> bottomView(Node* root) {
    vector<int> result;
    if (!root) return result;

    map<int, pair<int, int>> bottomNodes; // hd → {value, level}
    dfsBottom(root, 0, 0, bottomNodes);

    for (auto &it : bottomNodes) {
        result.push_back(it.second.first);
    }
    return result;
}

```

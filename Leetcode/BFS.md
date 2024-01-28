## BFS
### Binary Tree
#### 314. Binary Tree Vertical Order Traversal

1. **BFS + Sort**
   - **Time complexity**: O(N) [BFS] + O(NlogN) [Sort] = O(NlogN)
   - **Space Complexity**: O(N)
    ```cpp
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> verticalMap;
        queue<pair<TreeNode*, int>> q;
    
        if (root) {
            q.push({root, 0});
        }
    
        while (!q.empty()) {
            TreeNode *cur = q.front().first; 
            int cur_pos = q.front().second;
            q.pop();
            verticalMap[cur_pos].push_back(cur->val);
    
            if (cur->left) {
                q.push({cur->left, cur_pos - 1});
            }
            if (cur->right) {
                q.push({cur->right, cur_pos + 1});
            }
        }
    
        vector<vector<int>> res;
        for (const auto& entry : verticalMap) {
            res.push_back(entry.second);
        }
        return res;
    }
    ```

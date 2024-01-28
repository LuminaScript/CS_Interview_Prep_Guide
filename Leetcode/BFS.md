## Tree-Based BFS Questions
- [**Leetcode 314: Binary Tree Vertical Order Traversal**](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)
  > Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
  >
  > If two nodes are in the same row and column, the order should be from left to right.

  **Solution One: BFS + Sort**
  
  _Time Complexity: O(NlogN) + Space Complexity: O(N)_
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

- [Leetcode 102: Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [Leetcode 103: Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
  > Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
  
  _Time Complexity: O(N) + Space Comexity: O(N)_
  ```cpp
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if(!root) return res;
      queue<TreeNode*> q;
      q.push(root);
      bool leftToRight = true;
      
      while(!q.empty()){
          int n = q.size();
          vector<int> level(n);
          for(int i = 0; i < n; i++){
              TreeNode *node = q.front(); q.pop();
              // fill level array with zigzag order
              int index = leftToRight ? i : (n - i - 1);
              level[index] = node->val;

              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
          }
          leftToRight = !leftToRight;
          res.push_back(level);
      }
      return res;
  }
  ```
- [Leetcode 297: Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) (combines BFS and two-pointer approach)


### Graph-Based BFS Questions
- [Leetcode 200: Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [Leetcode 133: Clone Graph](https://leetcode.com/problems/clone-graph/)
- [Leetcode 127: Word Ladder](https://leetcode.com/problems/word-ladder/)
- [Leetcode 490: The Maze](https://leetcode.com/problems/the-maze/)
- [Leetcode 323: Connected Component in Undirected Graph](https://leetcode.com/problems/connected-component-in-undirected-graph/)
- [Leetcode 130: Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)
- [Leetcode 752: Open the Lock](https://leetcode.com/problems/open-the-lock/)
- [Leetcode 815: Bus Routes](https://leetcode.com/problems/bus-routes/)
- [Leetcode 1091: Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
- [Leetcode 542: 01 Matrix](https://leetcode.com/problems/01-matrix/)
- [Leetcode 1293: Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)
- [Leetcode 417: Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)

### Topological Sorting Questions
- [Leetcode 207: Course Schedule (I, II)](https://leetcode.com/problems/course-schedule/)
- [Leetcode 444: Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/)
- [Leetcode 269: Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)
- [Leetcode 310: Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/)
- [Leetcode 366: Find Leaves of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/)

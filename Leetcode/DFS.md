
## Depth-First Search (DFS)
### Tree-based DFS:
- [543 Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)[EASY]<br>

  DFS + In-order Traversal<br>
  Time Complexity: O(N) + Space Complexity: O(N)
  ```cpp
  int diameter = 0;
  int longestPath(TreeNode* node){
      if(!node) return 0;

      // post-order traversal + dfs
      int leftPath = longestPath(node->left); // left
      int rightPath = longestPath(node->right); // right
      diameter = max(diameter, leftPath + rightPath); // mid

      return max(leftPath, rightPath) + 1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
      longestPath(root);
      return diameter;
  }
  ```
- [124 Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) [HARD] <br>

  Time Complexity: O(N) + Space Complexity: O(N)
  ```cpp
  int max_sum = INT_MIN;
  int maxPath(TreeNode* node){
      if(!node) return 0;
      
      int leftMax = max(maxPath(node->left), 0); 
      int rightMax = max(maxPath(node->right), 0); 
      max_sum = max(max_sum, leftMax + rightMax + node->val); 

      return max(leftMax, rightMax) + node->val;
  }
  int maxPathSum(TreeNode* root) {
      maxPath(root);
      return max_sum;
  }
  ```

- [226 Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

  Time Complexity: O(N) + Space Complexity: O(N)
  ```cpp
  TreeNode* dfs(TreeNode* node){
      if(!node || !node->left && !node->right) return node;
      TreeNode* left = dfs(node->left); // left
      TreeNode* right = dfs(node->right); //right
      node->right = left, node->left = right; //mid
      return node;
  }
  TreeNode* invertTree(TreeNode* root) {
      return dfs(root);
  }

  ```

- [101 Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
- [951 Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/)
- [236 Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [105 Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- [104 Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [987 Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
- [1485 Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/)
- [572 Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)
- [863 All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
- [1110 Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)

### Binary Search Tree (BST):
- [230 Kth Smallest element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
- [98 Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
- [270 Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/)
- [235 Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- [669 Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/)
- [700 Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
- [108 Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [333 Largest BST Subtree](https://leetcode.com/problems/largest-bst-subtree/)
- [285 Inorder Successor in BST (I, II)](https://leetcode.com/problems/inorder-successor-in-bst/)
  
### Graph-based DFS:
- [341 Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/)
- [394 Decode String](https://leetcode.com/problems/decode-string/)
- [51 N-Queens (I, II similar)](https://leetcode.com/problems/n-queens/)
- [291 Word Pattern II (I is a simple hashmap problem)](https://leetcode.com/problems/word-pattern-ii/)
- [126 Word Ladder II (I is a BFS problem)](https://leetcode.com/problems/word-ladder-ii/)
- [93 Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)
- [22 Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
- [856 Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/)
- [301 Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)
- [37 Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
- [212 Word Search II (I, II)](https://leetcode.com/problems/word-search-ii/)
- [1087 Brace Expansion](https://leetcode.com/problems/brace-expansion/)
- [399 Evaluate Division](https://leetcode.com/problems/evaluate-division/)
- [1274 Number of Ships in a Rectangle](https://leetcode.com/problems/number-of-ships-in-a-rectangle/)
- [1376 Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/)
- [694 Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands/)
- [131 Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

## Combinatorial DFS:

### Permutations and Combinations:
- [17 Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
- [39 Combination Sum (I, II, III similar, IV is dynamic programming)](https://leetcode.com/problems/combination-sum/)
- [78 Subsets (I, II focus on deduplication)](https://leetcode.com/problems/subsets/)
- [46 Permutations (I, II focus on deduplication)](https://leetcode.com/problems/permutations/)
- [77 Combinations (I, II focus on deduplication)](https://leetcode.com/problems/combinations/)
- [698 Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)
- [526 Beautiful Arrangement (similar to 46)](https://leetcode.com/problems/beautiful-arrangement/)

### Memoization Search (DFS + Memoization Search):
- [139 Word Break II](https://leetcode.com/problems/word-break-ii/)
- [72 Edit Distance](https://leetcode.com/problems/edit-distance/)
- [377 Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)
- [1235 Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)
- [1335 Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)
- [1216 Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/)
- [97 Interleaving String](https://leetcode.com/problems/interleaving-string/)
- [472 Concatenated Words](https://leetcode.com/problems/concatenated-words/)
- [403 Frog Jump](https://leetcode.com/problems/frog-jump/)
- [329 Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

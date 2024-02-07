
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

  Time Complexity: O(N) + Space Complexity: O(N)
  ```cpp
  bool isMirror(TreeNode* n1, TreeNode* n2){
      if(!n1 && !n2) return true;
      if(!n1 || !n2) return false;
      return (n1->val == n2->val) && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
  }
  bool isSymmetric(TreeNode* root) {
      return isMirror(root->left, root->right);
  }

  ```

- [951 Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/)

  The time complexity: O(min(N1, N2)),  `N1` and `N2` are the total number of nodes in the input trees `root1` and `root2`.
  
  The space complexity: O(min(H1, H2)), where `H1` and `H2` are the heights of the trees of `root1` and `root2`.

  ```cpp
  bool flipEquiv(TreeNode* r1, TreeNode* r2) {
      if(!r1 && !r2) return true;
      if(!r1 || !r2 || r1->val != r2->val) return false;
      
      return flipEquiv(r1->left, r2->left) && flipEquiv(r1->right, r2->right)
          || flipEquiv(r1->left, r2->right) && flipEquiv(r1->right, r2->left);
  }
  
  ```
  
- [236 Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

  Time Complexity: O(N)
  
  Space Complexity: O(N), where the height of skewed tree is O(N).
  ```cpp
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !q || !p) return nullptr; // root does not find neitenr p nor q
    if (root==p || root==q) return root; // root found p or q

    TreeNode *left = lowestCommonAncestor(root->left, p, q); // continue on left subtree
    TreeNode *right = lowestCommonAncestor(root->right, p, q); // continue on right subtree
    if (left && right) return root; // CA in both subtree 
    else if (left == NULL && right != NULL) return right; // CA in right subtree
    else if (left != NULL && right == NULL) return left; // CA in left subtree
    else return NULL; // not found 
  }
  ```
- [105 Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

  Time Complexity: O(N)
  
  Space Complexity: O(N)
  ```cpp
  int preorderIndex = 0;
  unordered_map<int, int> inorderIndexMap; /*value -> index*/

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      for(int i = 0; i < inorder.size(); i++){
          inorderIndexMap.insert({inorder[i], i});
      }    
      return arrayToTree(preorder, 0, preorder.size() - 1);
  }
  
  TreeNode *arrayToTree(vector<int>& preorder, int left, int right){
      if(left > right) return nullptr;

      int rootValue = preorder[preorderIndex++];
      TreeNode *root = new TreeNode(rootValue);

      root->left = arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
      root->right = arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
      return root;
  }
  ```
- [104 Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

  Time Complexity: O(N)
  
  Space Complexity: O(N)
  ```cpp
  int maxDepth(TreeNode* root) {
      if(!root) return 0;
      if(!root->left && !root->right) return 1;
      return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
  }
  ```
- [987 Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
  
  Time Complexity : O(NlogN)

  Space Complexity : O(N)
  ```cpp
  map<pair<int, int>, vector<int>> mp; // vertical height -> node's value
  void dfs(TreeNode* root, int row, int col){
      if(!root) return ;
      mp[make_pair(row, col)].push_back(root->val);
      dfs(root->left, row + 1, col - 1);
      dfs(root->right, row + 1, col + 1);
      
  }
  vector<vector<int>> verticalTraversal(TreeNode* root) {
      dfs(root, 0, 0);
      vector<vector<int>> ans;
      map<int, vector<int>> _mp;
      for(auto p : mp){
          sort(p.second.begin(), p.second.end());
          for(auto e : p.second){
              _mp[p.first.second].push_back(e);
          }
      }

      for(auto p: _mp){
          ans.push_back(p.second);
      }

      return ans;

  }
  ```
- [1485 Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/)
  ```cpp
  map<Node*, NodeCopy*> seen;
  NodeCopy* dfs(Node* root){
      if(!root) return nullptr;
      if(seen.find(root) != seen.end()) return seen[root];

      NodeCopy *newRoot = new NodeCopy(root->val);
      seen[root] = newRoot;

      newRoot->left = dfs(root->left);
      newRoot->right = dfs(root->right);
      newRoot->random = dfs(root->random);
      return newRoot;
  }
  NodeCopy* copyRandomBinaryTree(Node* root) {
      NodeCopy *newRoot = dfs(root);
      return newRoot;
  }
  ```
- [572 Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) [EASY]

  ```cpp
  bool isIdentical(TreeNode* r1, TreeNode* r2){
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    return r1->val == r2->val && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
  }
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(!root) return false;
      if(isIdentical(root, subRoot)) return true;
      return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
  ```
- [863 All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

  Time Complexity : O(N)

  Space Complexity : O(N + M)
  ```cpp
  unordered_map<int, vector<int>> adjList; // [node val][nbs nodes]
  vector<int> ans;

  void buildGraph(TreeNode* root){
      if(!root) return ;
      if(root->left) {
          adjList[root->val].push_back(root->left->val);
          adjList[root->left->val].push_back(root->val);
          buildGraph(root->left);
      }
      if(root->right){
          adjList[root->val].push_back(root->right->val);
          adjList[root->right->val].push_back(root->val);
          buildGraph(root->right);
      }
      
  }

  void dfs(int cur_val, int prev_val, int cur_dis, int k){
      if(cur_dis == k){
          ans.push_back(cur_val); return ;
      }
      for(int nxt_val : adjList[cur_val]){
          if(prev_val != nxt_val)
              dfs(nxt_val, cur_val, cur_dis + 1, k);
      }
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      buildGraph(root);
      dfs(target->val, -1, 0, k);
      return ans;
  }
  ```
- [1110 Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)
  
  ```cpp
  vector<TreeNode*> ans;
    set<int> to_delete_set; // Using a set for faster lookups

    // Helper function to handle deletion and decide whether to add a node to ans
    void addToAnsIfNotNull(TreeNode* node) {
        if (node != nullptr) ans.push_back(node);
    }

    TreeNode* dfs(TreeNode* node) {
        if (!node) return nullptr;
        
        // Recursively delete nodes in left and right subtrees
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        
        // If current node needs to be deleted
        if (to_delete_set.count(node->val)) {
            // Add non-null children to ans as new roots
            addToAnsIfNotNull(node->left);
            addToAnsIfNotNull(node->right);
            // Return nullptr to parent, indicating this node is deleted
            return nullptr;
        }
        
        return node; // Return the possibly modified current node
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Initialize to_delete_set from to_delete vector for faster lookups
        to_delete_set = set<int>(to_delete.begin(), to_delete.end());
        
        // Start DFS; if root is not deleted, add it to ans
        if (dfs(root) != nullptr) ans.push_back(root);
        
        return ans;
    }
  ```

### Binary Search Tree (BST):
- [230 Kth Smallest element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
  ```cpp
  vector<int> inorder;
  void postorder(TreeNode* root, int k){
      if(!root || inorder.size() == k) return ;
      postorder(root->left, k);
      inorder.push_back(root->val);
      postorder(root->right, k);
  }
  int kthSmallest(TreeNode* root, int k) {
      postorder(root, k);
      return inorder[k - 1];
  }
  ```
- [98 Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
  ```cpp
  bool helper(TreeNode* rt, long min, long max){
      if(rt == NULL) return true;
      if(rt->val <= min || rt->val >= max) return false;
      return helper(rt->left, min, std::min(max, static_cast<long>(rt->val)))
          && helper(rt->right, std::max(static_cast<long>(rt->val), min), max);
  }
  bool isValidBST(TreeNode* root) {
      return helper(root, LONG_MIN, LONG_MAX);
  }
  ```
- [270 Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/)
  ```cpp
  map<double, vector<int>> mp; // dif - value;
  void dfs(TreeNode* root, double target) {
      if(!root){
          return ;
      }
      mp[abs(root->val - target)].push_back(root->val);
      if(root->val < target)
          dfs(root->right, target);
      else
          dfs(root->left, target);
      
  }
  int closestValue(TreeNode* root, double target) {
      dfs(root, target);
      sort(mp.begin()->second.begin(), mp.begin()->second.end());
      return mp.begin()->second[0];
      
      
  }
  ```
- [235 Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
  ```cpp
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      while(root){
          if((root->val > p->val) && (root->val > q->val))
              root = root->left;
          else if((root->val < p->val) && (root->val < q->val))
              root = root->right;
          else break;  
      }
      return root;
  }
  ```
- [700 Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

  Time Complexity: O(LogN)  Space Compleixty:O(logN)
  ```cpp
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL || root->val == val) return root;
    TreeNode* ret = NULL;
    if (root->val > val) 
        ret = searchBST(root->left, val);
    else 
        ret = searchBST(root->right, val);
    return ret;
  } 
  ```
- [108 Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) [EASY]

  Time Complexity: O(N) Space Complexity: O(logN) - recursive stack is height-balanced

  > Strategy: always choose left middle node in preorder dfs traversal
  ```cpp
  TreeNode* dfs(vector<int>& nums, int left, int right){
    if(left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* left_subtree = dfs(nums, left, mid - 1);
    TreeNode* right_subtree = dfs(nums, mid + 1, right);
    return new TreeNode(nums[mid], left_subtree, right_subtree);

  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
      return dfs(nums, 0, nums.size() - 1);
  }
  ```
- [333 Largest BST Subtree](https://leetcode.com/problems/largest-bst-subtree/)

  Time: O(N) + Space: O(LogN)
  
  reference: https://leetcode.com/problems/largest-bst-subtree/solutions/78892/12ms-c-solution/
  ```cpp
  int largestBSTSubtree(TreeNode* root) {
      int res = 0, mn = INT_MIN, mx = INT_MAX;
      isValidBST(root, mn, mx, res);
      return res;
  }
  void isValidBST(TreeNode *root, int &mn, int &mx, int &res) {
      if (!root) return;
      int left_n = 0, right_n = 0;
      int left_mn = INT_MIN, right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
      isValidBST(root->left, left_mn, left_mx, left_n);
      isValidBST(root->right, right_mn, right_mx, right_n);
      if ((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)) {
          // current tree on root is BST
          res = left_n + right_n + 1; // right_subtree size + left_subtree size + root(1)
          mn = root->left ? left_mn : root->val; // set min to left_subtree 's max
          mx = root->right ? right_mx : root->val; // set max to right_subtree 's min
      } else res = max(left_n, right_n);
  }
  ```
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

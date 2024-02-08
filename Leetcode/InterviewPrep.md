## Arrays and Strings
- [Two Sum](https://leetcode.com/problems/two-sum/)
- [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
- [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
- [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
- [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
- [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
- [Jump Game](https://leetcode.com/problems/jump-game/)
- [Jump Game II](https://leetcode.com/problems/jump-game-ii/)
- [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- [Sort Colors](https://leetcode.com/problems/sort-colors/)
- [Word Search](https://leetcode.com/problems/word-search/)
- [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)

## Linked Lists
- [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

## Trees and Graphs
- [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
- [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
  
  O(N) + O(N)
  ```cpp
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return {};

    queue<TreeNode*> q;
    q.push(root);
    
    vector<vector<int>> res;
    bool leftStart = true;

    while(!q.empty()){
        int n = q.size();
        vector<int> level(n);
        for(int i = 0; i < n; i++){
            TreeNode *cur = q.front(); q.pop();
            int idx = leftStart ? i : (n - i - 1);
            level[idx] = cur->val;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            
        }
        leftStart = !leftStart;
        res.push_back(level);
    }
    return res;

  } 
  ```
  
- [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)

  O(LogN) + O(H)
  ```cpp
  TreeNode* findSucc(TreeNode* node){
    while(node->left){
        node = node->left;
    }
    return node;
  }
  TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root) return nullptr;
  
      TreeNode *cur = root, *par = nullptr;
  
      while(cur && cur->val != key){
          par = cur;
          if(cur->val > key) cur = cur->left;
          else cur = cur->right;
      } 
      if(!cur) return root;
  
      if(cur->left && cur->right){
          TreeNode* suc = findSucc(cur->right);
          cur->val = suc->val;
          cur->right = deleteNode(cur->right, suc->val);
      }else{
          TreeNode* chd = cur->left ? cur->left : cur->right;
          if(!par){
              root = chd;
          }else if(par->left == cur){ // cur is suc for it is smallest child
              par->left = chd;
          }else{ // either no children or only right -> nullptr or right child
              par->right = chd; 
          }
          delete cur;
  
      }
      return root;
  }
  ```

## Dynamic Programming
- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
- [Word Break](https://leetcode.com/problems/word-break/)
- [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

## Math and Geometry
- [Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)
- [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)

## Search and Sort
- [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)
- [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
- [Find the Closest Palindrome](https://leetcode.com/problems/find-the-closest-palindrome/)

## Design
- [LRU Cache](https://leetcode.com/problems/lru-cache/)
- [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
- [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
- [LFU Cache](https://leetcode.com/problems/lfu-cache/)
- [Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
- [Design Authentication Manager](https://leetcode.com/problems/design-authentication-manager/)

## Miscellaneous
- [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
- [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
- [Gas Station](https://leetcode.com/problems/gas-station/)
- [Maximal Square](https://leetcode.com/problems/maximal-square/)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
- [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)
- [Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/)
- [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)
- [Island Perimeter](https://leetcode.com/problems/island-perimeter/)
- [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
- [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)
- [Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)
- [Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)
- [Break a Palindrome](https://leetcode.com/problems/break-a-palindrome/)
- [Minimum One Bit Operations to Make Integers Zero](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/)
- [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)
- [Count Palindromic Subsequences](https://leetcode.com/problems/count-palindromic-subsequences/)
- [Reorganize String](https://leetcode.com/problems/reorganize-string/)
- [Degree of an Array](https://leetcode.com/problems/degree-of-an-array/)

# Algorithm and Data Structure Topics in Interviews

The following list includes frequently asked algorithm and data structure topics in job interviews. These topics are essential for technical interviews in various fields, and they cover a wide range of problem-solving techniques. Be sure to have a solid understanding of these topics to excel in technical interviews.

## Sorting Algorithms (Sort)

**Basic Knowledge:**
- Quick Sort and Merge Sort principles and code implementation.
- Understanding every line of code in Quick Sort and Merge Sort.
- Quick Sort: Average time complexity O(NlogN), space complexity O(1).
- Merge Sort: Worst-case time complexity O(NlogN), space complexity O(N).

**Beginner Problems:**
- Leetcode 148. Sort List
- Leetcode 56. Merge Intervals
- Leetcode 27. Remove elements

**Intermediate Problems:**
- Leetcode 179. Largest Number
- Leetcode 75. Sort Colors
- Leetcode 215. Kth Largest Element (can use heap-based solution)
- Leetcode 4. Median of Two Sorted Arrays

*Note: The last two problems are variants of Quick Select, similar to Quick Sort, and are frequently asked in interviews.*

## Linked Lists (Linked List)

**Basic Knowledge:**
- How to implement a linked list and traverse it.
- Linked lists offer O(1) insertion and deletion at the beginning and end, O(N) for arbitrary element search.

**Basic Problems:**
- Leetcode 206. Reverse Linked List
- Leetcode 876. Middle of the Linked List

**Intermediate Problems:**
- Leetcode 160. Intersection of Two Linked Lists
- Leetcode 141. Linked List Cycle (Linked List Cycle II)
- Leetcode 92. Reverse Linked List II
- Leetcode 328. Odd Even Linked List

## Heaps (Heap), Stacks, Queues, Hash Tables (HashMap, HashSet)

**Basic Knowledge:**
- Understanding the basic principles and complexity of these data structures.

**Queue Problems:**
- Leetcode 225. Implement Stack using Queues
- Leetcode 346. Moving Average from Data Stream
- Leetcode 281. Zigzag Iterator
- Leetcode 1429. First Unique Number
- Leetcode 54. Spiral Matrix
- Leetcode 362. Design Hit Counter

**Stack Problems:**
- Leetcode 155. Min Stack (followed by Leetcode 716 Max Stack)
- Leetcode 232. Implement Queue using Stacks
- Leetcode 150. Evaluate Reverse Polish Notation
- Leetcode 224. Basic Calculator II (I, II, III, IV)
- Leetcode 20. Valid Parentheses
- Leetcode 1472. Design Browser History
- Leetcode 1209. Remove All Adjacent Duplicates in String II
- Leetcode 1249. Minimum Remove to Make Valid Parentheses
- Leetcode 735. Asteroid Collision

**HashMap/HashSet Problems:**
- Leetcode 1. Two Sum
- [Leetcode 409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)
  ```cpp
  int longestPalindrome(string s) {
      unordered_map<char, int> mp;
      int len = 0;
      bool foundsingle = false;
      
      for(auto c : s) mp[c]++;

      for(auto p : mp){
          len += (p.second / 2) * 2;
          if(p.second % 2 == 1) foundsingle = true;
      }
      return foundsingle ? len + 1 : len;
  }
  ```
- Leetcode 146. LRU Cache (Use OrderedDict in Python)
- Leetcode 128. Longest Consecutive Sequence
- Leetcode 73. Set Matrix Zeroes
- Leetcode 380. Insert Delete GetRandom O(1)
- Leetcode 49. Group Anagrams
- Leetcode 350. Intersection of Two Arrays II
- Leetcode 299. Bulls and Cows
- Leetcode 348 Design Tic-Tac-Toe

**Heap/Priority Queue Problems:**
- Leetcode 973. K Closest Points
- Leetcode 347. Top k Largest Elements
- Leetcode 23. Merge K Sorted Lists
- Leetcode 264. Ugly Number II
- Leetcode 1086. High Five
- Leetcode 88. Merge Sorted Arrays
- Leetcode 692. Top K Frequent Words
- Leetcode 378. Kth Smallest Element in a Sorted Matrix
- Leetcode 295. Find Median from Data Stream (Use SortedDict for ease)
- Leetcode 767. Reorganize String
- Leetcode 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
- Leetcode 895. Maximum Frequency Stack

## Binary Search

**Basic Knowledge:**
- Binary search is a fundamental technique with time complexity O(logN).
- Common binary search problems can be categorized as explicit and implicit.

**Explicit Binary Search:**
- Leetcode 34. Find First and Last Position of Element in Sorted Array
- Leetcode 33. Search in Rotated Sorted Array
- Leetcode 1095. Find in Mountain Array
- Leetcode 162. Find Peak Element
- Leetcode 278. First Bad Version
- Leetcode 74. Search a 2D Matrix
- Leetcode 240. Search a 2D Matrix II

**Implicit Binary Search:**
- Leetcode 69. Sqrt(x)
- Leetcode 540. Single Element in a Sorted Array
- Leetcode 644. Maximum Average Subarray II
- Leetcode 528. Random Pick with Weight
- Leetcode 1300. Sum of Mutated Array Closest to Target
- Leetcode 1060. Missing Element in Sorted Array
- Leetcode 1062. Longest Repeating Substring
- Leetcode 1891. Cutting Ribbons
- Leetcode 410. Split Array Largest Sum (similar to 1891)

## Two Pointers (2 Pointer)

**Basic Knowledge:**
- Common two-pointer algorithms include same-direction, opposite-direction, and meeting-in-the-middle.
- Same-direction pointers move in the same direction, opposite-direction pointers move toward each other, and meeting-in-the-middle pointers start from both ends and meet in the middle.

**Opposite-direction Pointers:**
- Leetcode 409. Longest Palindrome
- Leetcode 125. Valid Palindrome (I, II)
- Leetcode 5. Longest Palindromic Substring
- Leetcode 647. Palindromic Substrings

**Meeting-in-the-middle Pointers:**
- Leetcode 1. Two Sum (using a two-pointer algorithm with sorting)
- Leetcode 167. Two Sum II - Input array is sorted
- Leetcode 15. 3Sum
- Leetcode 16. 3Sum Closest
- Leetcode 18. 4Sum
- Leetcode 454. 4Sum II
- Leetcode 277. Find the Celebrity
- Leetcode 11. Container With Most Water
- Leetcode 186 Reverse Words in a String II

**Same-direction Pointers:**
- Leetcode 283. Move Zeroes
- Leetcode 26. Remove Duplicate Numbers in Array
- Leetcode 395. Longest Substring with At Least K Repeating Characters
- Leetcode 340. Longest Substring with At Most K Distinct Characters
- Leetcode 424. Longest Repeating Character Replacement
- Leetcode 76. Minimum Window Substring
- Leetcode 3. Longest Substring Without Repeating Characters
- Leetcode 1004 Max Consecutive Ones III
- Leetcode 1658 Minimum Operations to Reduce X to Zero

## Breadth-First Search (BFS) Topics and Questions

### Basic Knowledge
- Common use cases of BFS include:
  - Finding the shortest path length in simple graphs (directed or undirected).
  - Topological sorting.
  - Traversing a graph or tree.
- BFS basic template (with or without recording levels).
- Time and space complexity: O(N + M), where N is the number of nodes, and M is the number of edges.
- Tree-based BFS does not require a separate set to track visited nodes.
- Graph-based BFS typically requires a set to track visited nodes.
- Topological Sorting: [Topological Sorting on Wikipedia](https://en.wikipedia.org/wiki/Topological_sorting)

### Tree-Based BFS Questions
- [Leetcode 102: Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [Leetcode 103: Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
- [Leetcode 297: Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) (combines BFS and two-pointer approach)
- [Leetcode 314: Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)
- [Leetcode 559: Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/)

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




## Depth-First Search (DFS)

### Basic Concepts:
- Common problems solved by DFS:
  1. Finding paths and their lengths in graphs (directed or undirected).
  2. Permutations and combinations.
  3. Traversing a graph or tree.
  4. Finding all solutions that meet specific criteria in a graph or tree.
- DFS Templates:
  - Template 1: Recording paths, no need for return values.
  - Template 2: Recording certain characteristics in return values.
- Time complexity is often exponential in most cases, usually O(number of solutions * time complexity per solution).
- Recursion problems can be implemented iteratively but are often more complex.

### Tree-based DFS:
- Remember templates for pre-order, in-order, and post-order traversal of binary trees.
- LeetCode Problems:
  - [543 Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)
  - [124 Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
  - [226 Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
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
- Characteristics of BST: In-order traversal yields a monotonically increasing binary tree. Operations (insertion, deletion, search) are O(h) where h is the height of the tree.
- Not all BST problems require recursion; some can be solved iteratively.
- LeetCode Problems:
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
- Typically requires a set to keep track of visited nodes to avoid infinite loops.
- Common in "Word" problems such as word break, word ladder, word pattern, and word search.
- LeetCode Problems:
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
- Similar to graph-based DFS but with a focus on permutations and combinations.
- LeetCode Problems:
  - [17 Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
  - [39 Combination Sum (I, II, III similar, IV is dynamic programming)](https://leetcode.com/problems/combination-sum/)
  - [78 Subsets (I, II focus on deduplication)](https://leetcode.com/problems/subsets/)
  - [46 Permutations (I, II focus on deduplication)](https://leetcode.com/problems/permutations/)
  - [77 Combinations (I, II focus on deduplication)](https://leetcode.com/problems/combinations/)
  - [698 Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)
  - [526 Beautiful Arrangement (similar to 46)](https://leetcode.com/problems/beautiful-arrangement/)

### Memoization Search (DFS + Memoization Search):
- A form of recursive dynamic programming that optimizes exponential DFS into polynomial time.
- These DFS must return values in the end (divide and conquer), not backtracking.
- Many dynamic programming problems can be solved using memoization search.
- LeetCode Problems:
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

## Prefix Sum:

### Basic Concepts:
- Pre-computing cumulative sums in an array for efficient range sum calculations.
- Common problems:
  - [53 Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
  - [1423 Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
  - [1031 Maximum Sum of Two Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/)
  - [523 Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)
  - [304 Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)

## Union Find (Disjoint Set):

### Basic Concepts:
- Merging multiple sets into one set.
- If data is not dynamically changing, use BFS or DFS. For data streams, union find has O(1) time complexity per operation.
- Learn the templates for union and find operations.
- LeetCode Problems:
  - [721 Accounts Merge](https://leetcode.com/problems/accounts-merge/)
  - [547 Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
  - [737 Sentence Similarity II](https://leetcode.com/problems/sentence-similarity-ii/)
  - [305 Number of Islands II](https://leetcode.com/problems/number-of-islands-ii/)

## Trie (Prefix Tree):

### Basic Concepts:
- A tree-like data structure for storing a dynamic set of strings.
- Can be replaced with a set that records all word prefixes, maintaining the same time complexity.
- LeetCode Problems:
  - [208 Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)
  - [211 Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)
  - [1268 Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)
  - [212 Word Search II](https://leetcode.com/problems/word-search-ii/)
  - [1166 Design File System](https://leetcode.com/problems/design-file-system/)

## Monotone Stack/Queue:

### Basic Concepts:
- Monotone stack is used to find the first greater/smaller element for each element in an array.
- Monotone queue is less common, but useful.
- Maintain a monotonic order (increasing or decreasing).
- LeetCode Problems:
  - [85 Maximum Rectangle](https://leetcode.com/problems/maximal-rectangle/)
  - [84 Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
  - [907 Sum of Subarray Minimums (similar to 84)](https://leetcode.com/problems/sum-of-subarray-minimums/)
  - [739 Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
  - [901 Online Stock Span](https://leetcode.com/problems/online-stock-span/)
  - [503 Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)

## Sweep Line Algorithm:

### Basic Concepts:
- A technique for handling time-related conflicts.
- Generally easy to understand and apply.
- LeetCode Problems:
  - [253 Meeting Room II (Meeting Room I is also relevant)](https://leetcode.com/problems/meeting-rooms-ii/)
  - [1094 Car Pooling](https://leetcode.com/problems/car-pooling/)
  - [218 The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)
  - [759 Employee Free Time](https://leetcode.com/problems/employee-free-time/)

## TreeMap:

### Basic Concepts:
- A tree-based hashmap with O(log N) complexity for insert, delete, search, and retrieve operations.
- SortedDict in Python can be used as an alternative.
- Provides methods like peekitem(k) and popitem(k) for more complex operations.
- LeetCode Problems:
  - [729 My Calendar I](https://leetcode.com/problems/my-calendar-i/)
  - [981 Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)
  - [846 Hand of Straights](https://leetcode.com/problems/hand-of-straights/)
  - [218 The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)
  - [480 Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)
  - [318 Count of Smaller Numbers After Self (can also be solved with Fenwick Tree and Segment Tree)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

## Dynamic Programming (DP):

### Simple DP
1. [Leetcode 70 Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
2. [Leetcode 64 Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)
3. [Leetcode 121 Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
4. [Leetcode 256 Paint House](https://leetcode.com/problems/paint-house/)
5. [Leetcode 45 Jump Game II](https://leetcode.com/problems/jump-game-ii/)
6. [Leetcode 91 Decode Ways](https://leetcode.com/problems/decode-ways/)
7. [Leetcode 44 Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)
8. [Leetcode 10 Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)

### Knapsack-Type DP
1. [Leetcode 518 Coin Change II](https://leetcode.com/problems/coin-change-2/)
2. [Leetcode 322 Coin Change](https://leetcode.com/problems/coin-change/)
3. [Leetcode 1043 Partition Array for Maximum Sum](https://leetcode.com/problems/partition-array-for-maximum-sum/)

### Prefix-Type DP
1. [Leetcode 1143 Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
2. [Leetcode 1062 Longest Repeating Substring](https://leetcode.com/problems/longest-repeating-substring/)
3. [Leetcode 718 Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

### Interval-Type DP
1. [Leetcode 312 Burst Balloons](https://leetcode.com/problems/burst-balloons/)
2. [Leetcode 1235 Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

### Sequence-Type DP
1. [Leetcode 674 Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)
2. [Leetcode 300 Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
3. [Leetcode 354 Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)
4. [Leetcode 87 Scramble String](https://leetcode.com/problems/scramble-string/)

### Others
1. [Leetcode 368 Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)
2. [Leetcode 55 Jump Game](https://leetcode.com/problems/jump-game/)
3. [Leetcode 132 Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/)
4. [Leetcode 639 Decode Ways II](https://leetcode.com/problems/decode-ways-ii/)
5. [Leetcode 712 Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)
6. [Leetcode 221 Maximal Square](https://leetcode.com/problems/maximal-square/)
7. [Leetcode 1277 Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)
8. [Leetcode 174 Dungeon Game](https://leetcode.com/problems/dungeon-game/)
9. [Leetcode 115 Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
10. [Leetcode 72 Edit Distance](https://leetcode.com/problems/edit-distance/)
11. [Leetcode 1048 Longest String Chain](https://leetcode.com/problems/longest-string-chain/)
12. [Leetcode 1140 Stone Game II](https://leetcode.com/problems/stone-game-ii/)


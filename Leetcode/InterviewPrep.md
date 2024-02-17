## Arrays and Strings
- [Two Sum](https://leetcode.com/problems/two-sum/)
  
  Time O(N), Space O(N)
  ```cpp
  vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> mp;
      for(int i = 0; i < nums.size(); i++){
          if(mp.find(target - nums[i]) == mp.end())
              mp[nums[i]] = i;
          else
              return{mp[target - nums[i]], i};
      }
      return {-1, -1};  
  }
  ```
- [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
  ```cpp
  int expand(int i, int j, string s){
      int left = i, right = j;
      
      while(left >= 0 && right < s.length() && s[left] == s[right]){
          left--;
          right++;
      }
      return right - left - 1;
  }
  string longestPalindrome(string s) {
      int n = s.size();
      vector<int> ans{2, 0};

      for(int i = 0; i < n; i++){
       int oddLength = expand(i, i, s);
          if (oddLength > ans[1] - ans[0] + 1) {
              int dist = oddLength / 2;
              ans[0] = i - dist;
              ans[1] = i + dist;
          }
          
          int evenLength = expand(i, i + 1, s);
          if (evenLength > ans[1] - ans[0] + 1) {
              int dist = (evenLength / 2) - 1;
              ans[0] = i - dist;
              ans[1] = i + 1 + dist;
          }
      }
      int i = ans[0], j = ans[1];
      return s.substr(i, j - i + 1);
  }
  ```
- [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
  
  : )
  
  Time O(N), Space O(1)
  ```cpp
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = -1;
    while(left < right){
        int h_left = height[left];
        int h_right = height[right];
        max_area = max(max_area, (right - left) * min(h_left, h_right));
        if(h_left < h_right)
            left++;
        else
            right--;
    }
    return max_area;
  }
  ```
- [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

  Time O(N), Space O(N)
  ```cpp
  bool isValid(string s) {
      stack<char> stack;
      for(auto c: s){
          if(c == '(' || c == '[' || c == '{')
              stack.push(c);
          else{
              if(stack.empty()) return false;
              char top = stack.top();
              if(top == '(' && c != ')' || (top == '{' && c != '}')|| (top == '[' && c != ']')) 
                  return false;
              stack.pop();
          }
      }
      return stack.empty();
  }
  ```
- [Group Anagrams](https://leetcode.com/problems/group-anagrams/)

  Time O(NK), Space O(NK)
  ```cpp
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; 
        vector<vector<string>> res; 

        for(string w : strs) {
            vector<int> count(26, 0); 
            for(char c : w) {
                count[c - 'a']++; 
            }
            
            string key = "";
            for(int i = 0; i < 26; ++i) {
                key += string(count[i], 'a' + i);
            }
            mp[key].push_back(w); 
        }

        for(auto p : mp) {
            res.push_back(p.second);
        }
        
        return res;
  }
  ```
- [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
  ```cpp
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int>leftgreat;
    int left = height[0];
    for(int j=0; j<n; j++){
        if(left <height[j]){
            left = height[j];
        }
        leftgreat.push_back(left);
    }
    int right = height[n-1];
    vector<int>rightgreat;
    for(int j = n-1 ; j>=0; j--){
            if(right<height[j])
                right = height[j];
        rightgreat.push_back(right);
        }
    reverse(rightgreat.begin() , rightgreat.end());
    int sum = 0;
    for(int i = 0 ; i<n;i++){
        sum = sum + (min(leftgreat[i] , rightgreat[i]) - height[i]);
    }
    return sum;
  }
  ```
- [Jump Game](https://leetcode.com/problems/jump-game/)
  ```cpp
  bool canJump(vector<int>& nums) {
    int furthestIndex = 0, n = nums.size();
    for(int i = 0; i < n; i++){
        if(furthestIndex >= i) furthestIndex = max(furthestIndex, i + nums[i]);
        if(furthestIndex >= n - 1) return true;
    }
    return false;
  }
  ```
- [Jump Game II](https://leetcode.com/problems/jump-game-ii/)

  Greedy Algorithm (OPTIMAL):
  ```cpp
  int jump(vector<int>& nums) {
    int ans = 0, n = nums.size();
    int curEnd = 0, curFar = 0;

    for(int i = 0; i < n - 1; i++){
        curFar = max(curFar, i + nums[i]);
        if(i == curEnd){
            ans++;
            curEnd = curFar;
        }
    }
    return ans;
  }
  ```

  Dynamic Programming:
  ```cpp
  int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; 
    for(int i = 0; i < n; i++){
        int jumps = nums[i];
        for(int j = 0; i + j < n && j <= jumps; j++){
            dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }    
    }
    return dp[n - 1];
  }
  ```
- [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
  ```cpp
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for(auto d : intervals){
        if(res.empty() || res.back()[1] < d[0]) res.push_back(d); // push d into interval if no overlap
        else res.back()[1] = max(res.back()[1], d[1]); // push the one with bigger right bound
    }
    return res;
  }
  ```
- [Sort Colors](https://leetcode.com/problems/sort-colors/)
  ```cpp
  void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
  }
  void sortColors(vector<int>& nums) {
    int p0 = 0;
    int p2 = nums.size() - 1;
    for(int i = 0; i <= p2;){
        if(nums[i] == 0){
            swap(&nums[i++], &nums[p0++]);
        }
        else if(nums[i] == 2){
            swap(&nums[i], &nums[p2--]);
        }else{
            i++;
        }
    }
  } 
  ```
- [Word Search](https://leetcode.com/problems/word-search/)
  ```cpp
  vector<vector<char>> bd;
  int rn, cn;
  bool dfs(int i, int j, string word) {
      if(word.size() == 0) return true;
      if(i < 0 || i >= rn || j < 0 || j >= cn || bd[i][j] != word[0]) return false;
      char c = bd[i][j];
      bd[i][j] = '*';
      word = word.substr(1);
      bool ret = dfs(i + 1, j, word) || dfs(i - 1, j, word) || dfs(i, j + 1, word) || dfs(i, j - 1, word);
      bd[i][j] = c;
      return ret;

  }
  bool exist(vector<vector<char>>& board, string word) {
      bd = board;
      rn = board.size();
      cn = board[0].size();
      for(int i = 0; i < rn; i++){
          for(int j = 0; j < cn; j++){
              if(dfs(i , j, word)) return true;
          }
      }
      return false;
  }
  ```
- [Move Zeroes](https://leetcode.com/problems/move-zeroes/)

  O(N) Time + O(1) Space
  ```cpp
  void moveZeroes(vector<int>& nums) {
    int lastNonZero = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[lastNonZero++] = nums[i];
        }
    }
    for(int i = lastNonZero; i < nums.size(); i++){
        nums[i] = 0;
    }
  }
  ```
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

  O(N) Time + O(1) Space
  ```cpp
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int sum = 0, res = 0;
    mp[sum] = 1;
    for(auto n : nums){
        sum += n;
        res += mp[sum - k];
        mp[sum]++;
    }
    return res;
  }
  ```
- [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)
  ```cpp
  bool backspaceCompare(string s, string t) {
    int i = s.size() - 1, j = t.size() - 1;
    while (i >= 0 || j >= 0) {
        int backspaceCount = 0;
        while (i >= 0 && (backspaceCount > 0 || s[i] == '#')) {
            backspaceCount += s[i] == '#' ? 1 : -1;
            i--;
        }
        backspaceCount = 0;
        while (j >= 0 && (backspaceCount > 0 || t[j] == '#')) {
            backspaceCount += t[j] == '#' ? 1 : -1;
            j--;
        }
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false; // Characters do not match.
        }
        if ((i >= 0) != (j >= 0)) {
            return false; // One string ended but the other did not.
        }
        i--;
        j--;
    }
    return true; // Successfully compared all characters.
  }
  ```

## Linked Lists
- [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
  ```cpp
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *fast = dummy, *slow = dummy;

    // advanced fast to make fast & slow n nodes apart
    for(int i = 0; i <= n; i++)  fast = fast->next; 
    
    // move fast to end(nullptr), maintain the gap
    while(fast){
        fast = fast->next; 
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
  }  
  ```
- [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
  
  O(N) + O(1)
  ```cpp
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *dummy = new ListNode();
    ListNode *prev = dummy;
    while(list1 && list2){
        if(list1->val < list2->val){
            prev->next = list1;
            list1 = list1->next;
        }else{
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }
    prev->next = list1 ? list1 : list2;
    return dummy->next;
  }  
  ```
- [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

  Time Complexity: Queue Insertion O(KLogK) * O(N) = O(NlogK) ```k Lists``` ```N Nodes```

  Space Complexity: O(k) ```stores one Node from each list```
  ```cpp
  class Compare {
  public:
      bool operator() (ListNode *A, ListNode *B){
          return A->val > B->val;
      }
  };
  class Solution {
  public:
      ListNode* mergeKLists(vector<ListNode*>& lists) {
          priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
          ListNode *dummy = new ListNode(-1);
          ListNode *prev = dummy;
          for(auto n: lists)
              if(n) pq.push(n);
          while(!pq.empty()){
              ListNode *nd = pq.top(); pq.pop();
              prev->next = nd;
              prev = nd;
              if(nd->next) pq.push(nd->next);
          }
          return dummy->next;
      }
  };
  ```

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
  ```cpp
  int climbStairs(int n) {
    if(n <= 2) return n;
    vector<int> dp(n + 1, 1);
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
  ```
- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
  ```cpp
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 1);
    for(int i = 1; i < n; i++){
        int max = 1;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]) max = std::max(max, dp[j] + 1);
        }
        dp[i] = max;
    }

    int longest = 0;
    for(auto n : dp) longest = max(longest, n);

    return longest;
  }
  ```
- [Word Break](https://leetcode.com/problems/word-break/)
  
  Time Complexity:  convert wordDict into a set : ```O(m⋅k)``` + nested for ```loop O(n^2```) * substring operation ```O(n)``` = ```O(n*3 * m * k)```

  Space Compleixty: Dp array ```O(n)``` + Set ```O(m + k)``` = ```O(n + mk)```
  ```cpp
  vector<bool> dp(s.size() + 1, false); // dp[i] := does substrin of w with length i exists?
    unordered_set dict(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for(int i = 1; i <= s.size(); i++){ // string
        for(int j = 0; j < i; j++){
            string word = s.substr(j, i - j); 
            if (dp[j] && dict.find(word) != dict.end()) {
                dp[i] = true;
                break; 
            }
        }
    }
    return dp[s.size()];
  }

  ```
- [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

  Time Complexity: ```O(m * n)``` Space Complexity: ```O(m * n)```
  ```cpp
  int longestCommonSubsequence(string X, string Y) {
    int m = X.size(), n = Y.size();
    vector<std::vector<int>> A(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            A[i][j] = X[i - 1] == Y[j - 1] ? A[i-1][j-1] + 1 : max(A[i-1][j], A[i][j-1]);
    
    return A[m][n];  // Length of the longest common subsequence
  }
  ```

## Math and Geometry
- [Pow(x, n)](https://leetcode.com/problems/powx-n/)
  
  Time Complexity: O(logn) + Space Complexity: O(1)
  ```cpp
  double myPow(double x, int n) {
    long long pow = abs(n);
    double ans = 1;
    while(pow){
        if(pow % 2 == 0){
            x *= x;
            pow /= 2;
        }else{
            ans *= x;
            pow--;
        }
    }
    return n > 0 ? ans : 1 / ans;
  }
  ```
- [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)
  ```cpp
  int maxPoints(vector<vector<int>>& points) {
    if(points.size() == 1) return 1;
    map<pair<int, int>, int> slope_cnt; // <delta_x, delta_y>, cnt
    int maxPoints = 0;
    
    for(int i = 0; i < points.size(); ++i) {
        int samePoint = 0, localMax = 0;
        slope_cnt.clear(); // Clear for each new point
        
        for(int j = 0; j < points.size(); ++j) {
            if(i == j) continue;
            
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            
            if(dx == 0 && dy == 0) { // Same point
                samePoint++;
                continue;
            }
            
            int gcd = __gcd(dx, dy);
            dx /= gcd;
            dy /= gcd;
            
            localMax = max(localMax, ++slope_cnt[{dx, dy}]);
        }
        
        maxPoints = max(maxPoints, localMax + samePoint + 1);
    }
    
    return maxPoints;
  }
  ```
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

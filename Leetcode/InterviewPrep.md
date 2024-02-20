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
  
  Time Complexity: O(logn), Space Complexity: O(1)
  ```cpp
  string convertToTitle(int columnNumber) {
    string ans;
    while (columnNumber) {
        columnNumber--;
        ans = (char)((columnNumber) % 26 + 'A') + ans;
        columnNumber = (columnNumber) / 26;
    }
    return ans;
  }
  ```

## Search and Sort in Matrix
- [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)
  ```cpp
  class Solution {
  public:
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
          if (matrix.empty() || matrix[0].empty()) return false;
          
          int row = 0;
          int col = matrix[0].size() - 1;
          
          while (row < matrix.size() && col >= 0) {
              if (matrix[row][col] == target) return true;
              else if (matrix[row][col] > target) col--;
              else row++;
          }
          
          return false;
      }
  };
  ```
- [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
  
  Solution 1: Priority Queue:
  ```cpp
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;
    int n = matrix.size();
    
    for(int i = 0; i < min(k, n); i++)
        for(int j = 0; j < min(k, n); j++)
            pq.push(matrix[i][j]);

    int size = pq.size(), cnt = size - k + 1;
    while(--cnt) pq.pop();
    
    return pq.top();
  }
  ```

  Solution 2 : BST (OPTIMAL)
  ```cpp
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int start = matrix[0][0], end = matrix[n - 1][n - 1];
    while (start < end) {
        int mid = start + (end - start) / 2;
        vector<int> smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};
        int count = countLessEqual(matrix, mid, smallLargePair);
        if (count == k)
            return smallLargePair[0];
        if (count < k)
            start = smallLargePair[1]; // search higher
        else
            end = smallLargePair[0]; // search lower
    }
    return start;
  }

  int countLessEqual(vector<vector<int>>& matrix, int mid, vector<int>& smallLargePair) {
      int count = 0;
      int n = matrix.size(), row = n - 1, col = 0;
      while (row >= 0 && col < n) {
          if (matrix[row][col] > mid) {
              smallLargePair[1] = min(smallLargePair[1], matrix[row][col]);
              row--;
          } else {
              smallLargePair[0] = max(smallLargePair[0], matrix[row][col]);
              count += row + 1;
              col++;
          }
      }
      return count;
  }
  ```
- [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
  
  ```cpp
  void setZeroes(vector<vector<int>>& matrix) {
    bool col0 = false;
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++){
        if(matrix[i][0] == 0) col0 = true;
        for(int j = 1; j < m; j++){
            if(matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if(col0) matrix[i][0] = 0;
    }
  }
  ```
- [Find the Closest Palindrome](https://leetcode.com/problems/find-the-closest-palindrome/)
  
- [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
  ```cpp
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sta;
        sta.push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (sta.top() != -1 && heights[sta.top()] >= heights[i]) {
                int height = heights[sta.top()];
                sta.pop();
                int width = i - sta.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            sta.push(i);
        }

        while (sta.top() != -1) {
            int height = heights[sta.top()];
            sta.pop();
            int width = heights.size() - sta.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
                if (matrix.size() == 0) {
            return 0;
        }
        vector<int> heights(matrix[0].size(), 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                else {
                    heights[j] += matrix[i][j] - '0';
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
  }
  ```

  - [Maximal Square](https://leetcode.com/problems/maximal-square/)
  ```cpp
  int findmin(int i, int j, int k){
      if(i <= j && i <= k) return i;
      if(j <= i && j <= k) return j;
      return k;
  }
  int maximalSquare(vector<vector<char>>& matrix) {
      int rn = matrix.size(), cn = matrix[0].size();
      vector<vector<int>> dp(rn, vector<int>(cn, 0));
      int maxside = 0;
      for(int i = 0; i < matrix.size(); i++){
          for(int j = 0; j < matrix[0].size(); j++){
              if(matrix[i][j] == '1'){
                  if(i == 0 || j == 0) dp[i][j] = 1;
                  else dp[i][j] = findmin(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
              }
              maxside = max(maxside, dp[i][j]);
          }
      }
      return maxside * maxside;
  }
  ```

## Design
- [LRU Cache](https://leetcode.com/problems/lru-cache/)
  ```cpp
  struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
  };


  class LRUCache {
  public:
      int capacity;
      unordered_map<int, Node*> dic;
      Node *head = new Node(-1, -1);
      Node *tail = new Node(-1, -1);
      LRUCache(int capacity) {
          this->capacity = capacity;
          head->next = tail;
          tail->prev = head;
      }
      
      int get(int key) {
          if (dic.find(key) == dic.end()) {
              return -1;
          }
          
          Node *node = dic[key];
          remove(node);
          add(node);
          return node->val;
      }
      
      void put(int key, int value) {
          if (dic.find(key) != dic.end()) {
              Node *oldNode = dic[key];
              remove(oldNode);
          }
          
          Node *node = new Node(key, value);
          dic[key] = node;
          add(node);
          
          if (dic.size() > capacity) {
              Node *nodeToDelete = head->next;
              remove(nodeToDelete);
              dic.erase(nodeToDelete->key);
          }
      }
      
      void add(Node *node) {
          Node *previousEnd = tail->prev;
          previousEnd->next = node;
          node->prev = previousEnd;
          node->next = tail;
          tail->prev = node;
      }
      
      void remove(Node *node) {
          node->prev->next = node->next;
          node->next->prev = node->prev;
      }
  
  };
  ```
- [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
- [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
- [LFU Cache](https://leetcode.com/problems/lfu-cache/)
- [Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
- [Design Authentication Manager](https://leetcode.com/problems/design-authentication-manager/)


### Monotone Stack
- [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)
  ```cpp
  string removeDuplicateLetters(string s) {
    if (s.size() == 1) return s;

    unordered_map<char, int> cnt;
    stack<char> monostack;
    unordered_set<char> seen;

    for (char c : s) cnt[c]++;

    for (char c : s) {
        cnt[c]--; // Decrease the count of character c
        if (seen.find(c) != seen.end()) continue;

        while (!monostack.empty() && monostack.top() > c && cnt[monostack.top()] > 0) {
            seen.erase(monostack.top());
            monostack.pop();
        }

        monostack.push(c);
        seen.insert(c);
    }

    string ans = "";
    while (!monostack.empty()) {
        ans = monostack.top() + ans;
        monostack.pop();
    }
    return ans;
  }
  ```

  - [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
  ```cpp
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    int i = 0, j = 0;
    while(j < nums.size()){
        while(!dq.empty() && nums[j] > dq.back()) dq.pop_back();
        dq.push_back(nums[j]);
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            ans.push_back(dq.front());
            if (dq.front() == nums[i]){
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
  }
  ```

### Greedy
- [Gas Station](https://leetcode.com/problems/gas-station/)

  Time Complexity: O(n) + Space Complexity: O(1)
  ```cpp
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int currGain = 0, totalGain = 0, answer = 0;
      
      for (int i = 0; i < gas.size(); ++i) {
          totalGain += gas[i] - cost[i];
          currGain += gas[i] - cost[i];
          if (currGain < 0) {
              answer = i + 1;
              currGain = 0;
          }
      }
      return totalGain >= 0 ? answer : -1;  
  }
  ```



- [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)

  O(nlogn) + O(n)
  ```cpp
  static inline bool cmpStart(vector<int> x, vector<int> y){
    return x[0] < y[0];
  }

  int minMeetingRooms(vector<vector<int>>& intervals) {
      if (intervals.size() == 0) return 0;
      sort(intervals.begin(), intervals.end(), cmpStart);
      int cnt = 0;
      priority_queue<int, vector<int>, greater<int>> pq; 
      for (const auto& interval : intervals) {
          if (!pq.empty() && pq.top() <= interval[0]) 
              pq.pop(); 
          pq.push(interval[1]); 
          cnt = max(cnt, (int)pq.size()); 
      }
      return cnt;
  }
  ```

### Hash Table
- [Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/)
  ```cpp
  class Logger {
  public:
      unordered_map<string, int> mp;
      Logger() {}
      
      bool shouldPrintMessage(int timestamp, string message) {
          if(mp.find(message) == mp.end() || timestamp - mp[message] >= 10){
              mp[message] = timestamp;
              return true;
          }
          return false;
      }
  
  };
  ```
- [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)
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
### Other
- [Island Perimeter](https://leetcode.com/problems/island-perimeter/)

  Note: any combination of (left + top), (left + bottom), (right + top), (right, bottom)
  ```cpp
  int islandPerimeter(vector<vector<int>>& grid) {
      int res = 0, rn = grid.size(), cn = grid[0].size();
      for(int r = 0; r < rn; r++){
          for(int c = 0; c < cn; c++){
              if(grid[r][c] == 1){
                  res += 4;
                  if(r < rn - 1 && grid[r + 1][c] == 1) res -= 2; 
                  if(c < cn - 1 && grid[r][c + 1] == 1) res -= 2; 
              }
          }
      }
      return res;
  }
  ```
- [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
  ```cpp
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(mid % 2 == 1) mid--;
        if(nums[mid] != nums[mid + 1]) right = mid;
        else left = mid + 2;
    }
    return nums[left];
  }
  ```
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

- [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs) 🟢 EASY 🔵 1-d DP
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
- [120. Triangle](https://leetcode.com/problems/triangle/description/) **```🟠MED```**    **```Time: O(N^2), Space: O(N)```**
  

  ```cpp
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> prev(1);
    prev[0] = triangle[0][0];
    for(int i = 1; i < n; i++){
        vector<int> cur(i + 1);
        for(int j = 0; j <= i; j++){
            if(j > prev.size() - 1) cur[j] = prev[j - 1] + triangle[i][j];
            else if(j == 0) cur[j] = prev[j] + triangle[i][j];
            else cur[j] = min(prev[j], prev[j - 1]) + triangle[i][j];
        }
        prev = cur;
    }
    int minPathSum = INT_MAX;
    for(auto n : prev){
        if(n < minPathSum) minPathSum = n;
    }
    return minPathSum;
  }
  ```
- [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) 🟢 EASY 🔵 1-d DP
  ```cpp
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int dp0 = cost[0], dp1 = cost[1];
    if(n == 2) return min(dp0, dp1);
    for(int i = 2; i <= n; i++){
        int temp = min(dp0, dp1);
        if(i < n) temp += cost[i];
        dp0 = dp1;
        dp1 = temp;
    }
    return dp1;
  }
  ```
- [198. House Robber](https://leetcode.com/problems/house-robber/) 🟠 MEDIUM 🔵 1-d DP
  ```cpp
  int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
  }
  ```
- [213. House Robber II](https://leetcode.com/problems/house-robber-ii/) 🟠 MEDIUM 🔵 1-d DP
  ```cpp
  int rob1(vector<int>& nums, int start, int end) {
      int n = end - start + 1;
      vector<int> dp(n + 1, 0);
      dp[0] = nums[start];
      dp[1] = max(nums[start], nums[start + 1]);
      for(int i = 2; i < n; i++){
          dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
      }
      return dp[n - 1];
  }
  int rob(vector<int>& nums) {
      int n = nums.size();
      if(n == 1) return nums[0];
      if(n == 2) return max(nums[0], nums[1]);
      return max(rob1(nums, 0, n - 2), rob1(nums, 1, n - 1));
  }
  ```
- [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring) 🟠 MEDIUM 🔵 1-d DP
  
  > Expand from center
  
  **Time: O(N^2), Space: O(1)**
  ```cpp
  int expand(string s, int l, int r){
    while(l >= 0 && r < s.size()){
        if(s[l] == s[r]){
            l--, r++;
        }else{
            break;
        }
    }
    return r - l + 1 - 2;
  }
  string longestPalindrome(string s) {
    int ans[2] = {0}, dist = 1;
    for(int i = 0; i < s.size(); i++){
        int oddLen = expand(s, i, i);
        if(oddLen > dist){
            ans[0] = i - oddLen / 2;
            ans[1] = i + oddLen / 2;
            dist = oddLen;
        }

        int evenLen = expand(s, i, i + 1);
        if(evenLen > dist){
            ans[0] = i - evenLen / 2 + 1;
            ans[1] = i + evenLen / 2;
            dist = evenLen;
        }
    }
    return s.substr(ans[0], dist);
  }
  ```

- [647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) 🟠 MEDIUM 🔵 1-d DP
  
  > Expand from center
  
  **Time: O(N^2), Space: O(1)**
  ```cpp
  int countSubstrings(string s) {
    int cnt = 0, n = s.size();
    for(int i = 0; i < n; i++){
        for(int l = i, r = i; l >= 0 && r < n; l--, r++){
            if(s[l] == s[r]) cnt++;
            else break;
        }
        for(int l = i, r = i + 1; l >= 0 && r < n; l--, r++){
            if(s[l] == s[r]) cnt++;
            else break;
        }           
    }
    return cnt;
  }
  ```

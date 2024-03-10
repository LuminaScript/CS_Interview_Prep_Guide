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

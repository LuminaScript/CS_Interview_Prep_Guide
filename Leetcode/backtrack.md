- [51. N-Queens](https://leetcode.com/problems/n-queens/) 🔴 HARD 🔵 Backtrack
  
  **Time: ```O(N!)```, Space: ```O(N^2)```**
  ```cpp
  vector<vector<string>> sols;
  vector<vector<string>> solveNQueens(int n) {
      vector<string> board(n, string(n, '.')); // Initialize the board with '.'
      set<int> columns; // Tracks columns where queens are placed.
      set<int> diag1; // Tracks \ diagonals where queens are placed.
      set<int> diag2; // Tracks / diagonals where queens are placed.
      
      backtrack(0, n, board, columns, diag1, diag2);
      return sols;
  }
  
  void backtrack(int row, int n, vector<string>& board, set<int>& columns, set<int>& diag1, set<int>& diag2) {
      if (row == n) {
          sols.push_back(board); // Found a solution.
          return;
      }
      
      for (int col = 0; col < n; ++col) {
          if (columns.count(col) || diag1.count(row - col) || diag2.count(row + col)) continue; // Check if the queen placement is safe.
  
          // Place the queen.
          board[row][col] = 'Q';
          columns.insert(col);
          diag1.insert(row - col);
          diag2.insert(row + col);
  
          // Move to the next row.
          backtrack(row + 1, n, board, columns, diag1, diag2);
  
          // Remove the queen (backtrack).
          board[row][col] = '.';
          columns.erase(col);
          diag1.erase(row - col);
          diag2.erase(row + col);
      }
  }
  ```
- [52. N-Queens](https://leetcode.com/problems/n-queens-ii/) 🔴 HARD 🔵 Backtrack
  
  **Time: ```O(N!)```, Space: ```O(N^2)```**
  ```cpp
  int sols = 0;
  void backtrack(int row, int n, set<int>& columns, set<int>& diag1, set<int>& diag2) {
      if (row == n) {
          sols++;
          return;
      }
      
      for (int col = 0; col < n; ++col) {
          if (columns.count(col) || diag1.count(row - col) || diag2.count(row + col)) continue; // Check if the queen placement is safe.
  
          columns.insert(col);
          diag1.insert(row - col);
          diag2.insert(row + col);
  
          backtrack(row + 1, n, columns, diag1, diag2);
  
          columns.erase(col);
          diag1.erase(row - col);
          diag2.erase(row + col);
      }
  }
  int totalNQueens(int n) {
      set<int> columns; 
      set<int> diag1; 
      set<int> diag2;
      
      backtrack(0, n, columns, diag1, diag2);
      return sols;
  }
  ```
- [698. Partition to K Equal Sums Subset](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) 🟠 MEDIUM 🔵 Backtrack
  ```cpp
  vector<int> nums;
  set<int> full;
  bool backtrack(int subSum, int k, int i, vector<int>& subsets){
      if(i == nums.size()){
          for(auto n : subsets)
              if(subSum != n) return false;
          return true;
      }
      for(int set = 0; set < k; set++){
          if(subsets[set] + nums[i] <= subSum){
              subsets[set] += nums[i];
              if(backtrack(subSum, k, i + 1, subsets)) return true;
              subsets[set] -= nums[i];
              if (subsets[set] == 0 || subsets[set] + nums[i] == subSum) break;
          }
      }
      return false;
  }
  bool canPartitionKSubsets(vector<int>& nums, int k) {
      int sum = 0;
      for(auto n : nums) sum += n;

      if(sum % k != 0) return false;
      int subSum = sum / k;
      this->nums = nums;

      vector<int> subsets(k, 0); 
      return backtrack(subSum, k, 0, subsets);
  }
  ```

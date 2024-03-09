- [51. N-Queens](https://leetcode.com/problems/n-queens/)
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

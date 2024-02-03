## Tree-Based BFS Questions
- [**Leetcode 314: Binary Tree Vertical Order Traversal**](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)
  > Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
  >
  > If two nodes are in the same row and column, the order should be from left to right.

  **Solution One: BFS + Sort**
  
  _Time Complexity: O(NlogN) + Space Complexity: O(N)_
   ```cpp
   vector<vector<int>> verticalOrder(TreeNode* root) {
       map<int, vector<int>> verticalMap;
       queue<pair<TreeNode*, int>> q;
   
       if (root) {
           q.push({root, 0});
       }
   
       while (!q.empty()) {
           TreeNode *cur = q.front().first; 
           int cur_pos = q.front().second;
           q.pop();
           verticalMap[cur_pos].push_back(cur->val);
   
           if (cur->left) {
               q.push({cur->left, cur_pos - 1});
           }
           if (cur->right) {
               q.push({cur->right, cur_pos + 1});
           }
       }
   
       vector<vector<int>> res;
       for (const auto& entry : verticalMap) {
           res.push_back(entry.second);
       }
       return res;
   }
       ```

- [Leetcode 102: Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
  
  _Time Complexity: O(N) + Space Comexity: O(N)_

  ```cpp
  vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            while(n--){
                TreeNode *nd = q.front();q.pop();
                level.push_back(nd->val);
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
            ans.push_back(level);
        }
        return ans;
  }

  ```
- [Leetcode 103: Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
  > Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
  
  _Time Complexity: O(N) + Space Comexity: O(N)_
  ```cpp
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if(!root) return res;
      queue<TreeNode*> q;
      q.push(root);
      bool leftToRight = true;
      
      while(!q.empty()){
          int n = q.size();
          vector<int> level(n);
          for(int i = 0; i < n; i++){
              TreeNode *node = q.front(); q.pop();
              // fill level array with zigzag order
              int index = leftToRight ? i : (n - i - 1);
              level[index] = node->val;

              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
          }
          leftToRight = !leftToRight;
          res.push_back(level);
      }
      return res;
  }
  ```
- [Leetcode 297: Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) (combines BFS and two-pointer approach)
  
- [Leetcode 559: Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/)

  Time Complexity: O(N) + Space Complexity: O(N)
  ```cpp
  int maxDepth(Node* root) {
    if (!root) return 0;
    stack<pair<Node*, int>> stk;
    stk.push(make_pair(root, 1));
    int depth = 0;
    while(!stk.empty()){
        auto cur = stk.top(); stk.pop();
        root = cur.first;
        int cur_dep = cur.second;
        if(root){
            depth = std::max(depth, cur_dep);
            for(auto c : root->children){
                stk.push({c, cur_dep + 1});
            }

        }
    }
    return depth;
}
  ```

### Graph-Based BFS Questions
- [Leetcode 200: Number of Islands](https://leetcode.com/problems/number-of-islands/)

  Time Complexity : O(N * M) + Space Complexity : O(min(N, M))
  
  ```cpp
  int numIslands(vector<vector<char>>& grid) {
      int nr = grid.size();
      if(!nr) return 0;
      int nc = grid[0].size();
      int num_islands = 0;
      for(int r = 0; r < nr; r++){
          for(int c = 0; c < nc; c++){
              if(grid[r][c] == '1'){
                  num_islands++;
                  grid[r][c] = '0';
                  queue<pair<int, int>> nbs; // neighbors
                  nbs.push({r, c});
                  while(!nbs.empty()){
                      auto rc = nbs.front(); nbs.pop();
                      int row = rc.first, col = rc.second;
                      if(row - 1 >= 0 && grid[row - 1][col] == '1'){ // up
                          grid[row - 1][col] = '0';
                          nbs.push({row - 1, col});
                      }
                      if(row + 1 < nr && grid[row + 1][col] == '1'){ // down
                          grid[row + 1][col] = '0';
                          nbs.push({row + 1, col});
                      }
                      if(col - 1 >= 0 && grid[row][col - 1] == '1'){ // left
                          grid[row][col - 1] = '0';
                          nbs.push({row, col - 1});
                      }
                      if(col + 1 < nc && grid[row][col + 1] == '1'){ // right
                          grid[row][col + 1] = '0';
                          nbs.push({row, col + 1});
                      }

                  }

              }
          }
      }
        return num_islands;
    }
  ```
- [Leetcode 133: Clone Graph](https://leetcode.com/problems/clone-graph/)

  Time Complexity: O(N + M) + Space Complexity: O(N)

  * _Space Complexity: This space is occupied by the visited hash map and in addition to that, space would also be occupied by the recursion stack since we      are adopting a recursive approach here. The space occupied by the queue would be equal to O(H) where HHH is the height of the graph. Overall, the space       complexity would be O(N)_

  ```cpp
   Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        map<int, Node*> mp; // store the visited node
        queue<Node*> q; // store the to-be copy node in old graph
        Node *nd = new Node(node->val);
        mp[node->val] = nd;
        q.push(node);

        while(!q.empty()){
            Node *old_nd = q.front(); q.pop();
            for(Node* nb : old_nd->neighbors){
                if(mp.find(nb->val) == mp.end()){ // enqueue unvisited neighbors
                    mp[nb->val] = new Node(nb->val); // make deep copy of neighbors
                    q.push(nb);
                }
                mp[old_nd->val]->neighbors.push_back(mp[nb->val]);
            }  
        }
        
        return mp[node->val];
    }

  ```

- [Leetcode 127: Word Ladder](https://leetcode.com/problems/word-ladder/)

  Time Complexity: O(N * M) + Space Complexity: O(N)

  ```cpp
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> notVisited(wordList.begin(), wordList.end());
  
      // Early exit
      if (notVisited.find(endWord) == notVisited.end()) return 0;
  
      queue<string> q;
      int len = 1;
      q.push(beginWord);
  
      while (!q.empty()) {
          int levelSize = q.size(); // number of elements at the current level
          for (int i = 0; i < levelSize; i++) {
              string word = q.front(); q.pop();
              if (word == endWord) return len;
  
              // bfs search
              for(int j = 0; j < word.size(); j++){
                  for(char k = 'a'; k <= 'z'; k++){
                      string w = word;
                      w[j] = k;
                      if(notVisited.find(w) != notVisited.end()){
                          q.push(w);
                          notVisited.erase(w);
                      }
                  }
              }
          }
          len++;  // Increment length after processing all nodes at the current level
      }
      return 0;
  }

  ```

- [Leetcode 490: The Maze](https://leetcode.com/problems/the-maze/)

  ```cpp

  bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
  {
      int m = maze.size();
      int n = maze[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      vector<int> dirX{0, 1, 0, -1};
      vector<int> dirY{-1, 0, 1, 0};

      queue<vector<int>> q;
      q.push(start);
      visited[start[0]][start[1]] = true;

      while(!q.empty()){
          vector<int> cur = q.front(); q.pop();
          if(cur[0] == destination[0] && cur[1] == destination[1]) return true;

          for(int i = 0; i < 4; i++){
              int r = cur[0];
              int c = cur[1];
              while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0) {
                  r += dirX[i];
                  c += dirY[i];
              }
              r -= dirX[i];
              c -= dirY[i];
              if (!visited[r][c]) {
                  q.push({r, c});
                  visited[r][c] = true;
              }
          }
      }        
      return false;
  }

  ```
- [Leetcode 323: Connected Component in Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/)

  Time Complexity: O(N*2) + Space Complexity: O(N + E)
  
  ```cpp
  int countComponents(int n, vector<vector<int>>& edges) {
      if (n == 1) return 1;
      vector<vector<int>> g(n); // O(E)
      for(vector<int> e : edges){
          int par = e[0];
          int chd = e[1];
          g[chd].push_back(par);
          g[par].push_back(chd);
      }

      unordered_set<int> visited; // O(N)
      int cnt = 0;
      for(int i = 0; i < n; i++){ // O(N)
          if(visited.find(i) == visited.end()){ // new unvisited node = start of a new cc
              cnt++; 
              queue<int> q; // O(N)
              q.push(i);
              visited.insert(i);
              while(!q.empty()){ // O(N) : bfs on unvisited node -> visit all one in this cc
                  int curr = q.front(); q.pop();
                  for(int nb : g[curr]){
                      if(visited.find(nb) == visited.end()){
                          q.push(nb);
                          visited.insert(nb);
                      }
                  }
              }
          }
      }
      return cnt;
  }
  ```

- [Leetcode 130: Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)
  
  _Solution Source: https://leetcode.com/problems/surrounded-regions/solutions/4408885/bfs-faster-than-97-c_

  _Time Complexity: O(NM) + Space Complexity: O(NM)_

  ```cpp
  void solve(vector<vector<char>>& board) {
      int n=board.size(),m=board[0].size();
      vector<vector<int>> visited(n,vector<int>(m,0));
      vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
      queue<pair<int,int>> q;

      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(i>0 && i<n-1 && j>0 && j<m-1){continue;}
              if(board[i][j]=='O'){
                  q.push({i,j});
                  visited[i][j]=1;
              }
          }
      }

      while(!q.empty()){
          auto [x,y]=q.front();
          q.pop();
          for(auto d:dir){
              int row=x+d[0];
              int col=y+d[1];

              if(row>=0 && row<n && col>=0 && col<m && board[row][col]=='O' && visited[row][col]==0){
                  visited[row][col]=1;
                  q.push({row,col});
              }
          }
      }

      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(visited[i][j]==0 && board[i][j]=='O'){
                  board[i][j]='X';
              }
          }
      }
  }
  ```

- [Leetcode 752: Open the Lock](https://leetcode.com/problems/open-the-lock/)
- [Leetcode 815: Bus Routes](https://leetcode.com/problems/bus-routes/)
  ```cpp
  class Solution {
  public:
      int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
          if(s == t) return 0;
  
          unordered_map<int, vector<int>> adjList;
          for(int route = 0; route < routes.size(); route++){
            for(auto stop: routes[route]){
                adjList[stop].push_back(route);
            }
          }
  
          queue<int> q;
          unordered_set<int> vis;
          for(auto route : adjList[s]){
              q.push(route);
              vis.insert(route);
          }
  
          int busCnt = 1;
          while(!q.empty()){
              int size = q.size();
              for(int i = 0; i < size; i++){
                  int route = q.front(); q.pop();
  
                  for(int stop : routes[route]){
                      if(stop == t){
                          return busCnt;
                      }
                      for(int nextRoute : adjList[stop]){
                          if(vis.count(nextRoute) == 0){
                              vis.insert(nextRoute);
                              q.push(nextRoute);
                          }
                      }
                  }
              }
              busCnt++;
          }
          return -1;
      }
  };

  ```

- [Leetcode 1091: Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
- [Leetcode 542: 01 Matrix](https://leetcode.com/problems/01-matrix/)
- [Leetcode 1293: Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)
- [Leetcode 417: Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)

### Topological Sorting Questions
- [Leetcode 207: Course Schedule (I, II)](https://leetcode.com/problems/course-schedule/)

  Time Complexity : O(M + N) + Space Complexity : O(M + N)

  ```cpp
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto preq : prerequisites){
            adj[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int nodesVisited = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            nodesVisited++;

            for(int nbs : adj[node]){
                if(--indegree[nbs] == 0) q.push(nbs);
            }
        }
        return nodesVisited == numCourses;
    }

  ```

- [Leetcode 444: Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/)
- [Leetcode 269: Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)
- [Leetcode 310: Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/)

  Time Complexity: O(|V|) + Space Complexity: O(|V|)
  
  ```cpp
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      if(n == 1) return {0};
      vector<vector<int>> graph(n);
      vector<int> indegree(n, 0), ans; //vector<int> indegree keeps count of the number of nodes approaching a node
      
      for(auto &e : edges){   //Creating an adjacency matrix for the given graph
          graph[e[0]].push_back(e[1]);
          graph[e[1]].push_back(e[0]);
          indegree[e[0]]++;
          indegree[e[1]]++;
      }
      
      queue<int> q;
      for(int i=0; i<n;i++){
          if(indegree[i]==1) q.push(i), indegree[i]--; //add all the leaf nodes to the queue
      } 
      
      while(!q.empty()){
          int s = q.size();
          if(n <= 2) break;
          for(int i=0; i<s;i++){
              int curr = q.front(); q.pop();
              n--;
              for(auto child : graph[curr]){ 
                  indegree[child]--;
                  if(indegree[child]==1) q.push(child);   
              }
          }
      }
      while(!q.empty()){
          ans.push_back(q.front()); q.pop();
      }
      return ans;
      
  }

  ```

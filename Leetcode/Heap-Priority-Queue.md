- [703. Kth Largest Element In a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) 🟢 EASY 🔵 Min Heap

  ```N``` as the length of nums and ```M``` as the number of calls to ```add()```

  **Time : ```O(N⋅log⁡(N) + M⋅log⁡(k))``` | Space : ```O(N)```**
  ```cpp
  priority_queue<int, vector<int>, greater<int>> q;
  int k;
  KthLargest(int k, vector<int>& nums) {
      this->k = k;
      for(auto n : nums) add(n);
  }
  
  int add(int val) {
      q.push(val);
      if(q.size() > k) q.pop();
      return q.top();
  }
  ```
- [1046. Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) 🟢 EASY 🔵 Max Heap

  Each time around the main loop, there is a net loss of either 1 or 2 stones. Thus ```N - 1``` Maximum Itererations. 

  **Time : ```O(NlogN)``` | Space : ```O(N)```**
  ```cpp
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxheap;
    for(int n : stones) maxheap.push(n);
    while(maxheap.size() > 1){
        int x = maxheap.top(); maxheap.pop();
        int y = maxheap.top(); maxheap.pop();
        if(x < y) maxheap.push(y - x);
        else if(x > y) maxheap.push(x - y);
    }
    return maxheap.empty() ? 0 : maxheap.top();
  }
  ```
- [973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) 🟠 MEDIUM 🔵 Min Heap 🔵 Hash Map
  ```cpp
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        
        for(int i = 0; i < points.size(); ++i) {
            double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push({-distance, i});
        }
        
        vector<vector<int>> res;
        while(k-- > 0 && !pq.empty()) {
            auto [dist, idx] = pq.top(); pq.pop();
            res.push_back(points[idx]);
        }
        
        return res;
    }
  ```
- [215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) 🟠 MEDIUM 🔵 Max Heap

  **Time :  ```O(nlogk)``` | Space : ```O(k)```**
  ```cpp
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int n : nums){
        pq.push(-n);
        if(pq.size() > k) pq.pop();
    }
    return -pq.top();
  }
  ```
- [621. Task Scheduler](https://leetcode.com/problems/task-scheduler/) 🟠 MEDIUM 🔵 Max Heap 🔵 Hash Map

  **Time :  ```O(nlogk)``` | Space : ```O(n)```** k is the # of task type
  ```cpp
  int leastInterval(vector<char>& tasks, int n) {
    if(n == 0) return tasks.size();

    unordered_map<char, int> mp;
    for(char c : tasks) mp[c]++;

    priority_queue<pair<int, char>> pq;
    for(auto p : mp) pq.push({p.second, p.first});
    
    int alltime = 0, cycle = n + 1;
    vector<char> seq;
    while(!pq.empty()){
        int time = 0;
        vector<pair<int, char>> tmp;
        for(int i = 0; i < cycle; i++){
            if(!pq.empty()){
                tmp.push_back(pq.top());
                pq.pop();
                time++;
            }
        }
        for(auto t : tmp){
            if(--t.first) pq.push(t);
        }
        alltime += !pq.empty() ? cycle : time;
    }
    return alltime;
  }
  ```
- [Design Twitter](https://leetcode.com/problems/design-twitter/) 🟠 MEDIUM 🔵 Max Heap 🔵 Hash Map
  ```cpp
  priority_queue<pair<int, pair<int, int>>> pq;
  int time = 0;
  unordered_map<int, set<int>> mp;
  Twitter() { }
  
  void postTweet(int userId, int tweetId) {
      pq.push({++time, {tweetId, userId}});
  }
  
  vector<int> getNewsFeed(int userId) {
      vector<int> tweetIds;
      vector<pair<int, pair<int, int>>> temp;
      auto followees = mp[userId];
      int cnt = 0;
      while(cnt < 10 && !pq.empty()){
          auto p = pq.top(); pq.pop();
          int followeeId = p.second.second;
          if(userId == followeeId || followees.find(followeeId) != followees.end()){
              tweetIds.push_back(p.second.first);
              cnt++;
          }
          temp.push_back(p);
      }
      for(auto t : temp) pq.push(t);
      return tweetIds;
  }
  
  void follow(int followerId, int followeeId) {
      mp[followerId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
      mp[followerId].erase(followeeId);
  }
  ```
- [Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array/)
- [Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/)
- [Single Threaded Cpu](https://leetcode.com/problems/single-threaded-cpu/)
- [Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/)
- [Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/)
- [Find The Kth Largest Integer In The Array](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/)
- [Reorganize String](https://leetcode.com/problems/reorganize-string/)
- [Longest Happy String](https://leetcode.com/problems/longest-happy-string/)
- [Car Pooling](https://leetcode.com/problems/car-pooling/)
- [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) 🟠 MEDIUM 🔵 Max Heap 🔵 Min Heap
  ```cpp
  priority_queue<int> lo; // max heap leep frist half
  priority_queue<int, vector<int>, greater<int>> hi; // min heap keep second half
  void addNum(int num) {
      lo.push(num);
      hi.push(lo.top()); lo.pop();
      if(lo.size() < hi.size()){
          lo.push(hi.top()); hi.pop();
      }
  }
  double findMedian() {
      if(lo.size() > hi.size())
          return lo.top();
      return ((double) lo.top() + hi.top()) * 0.5;
  }
  ```
- [Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team/)
- [IPO](https://leetcode.com/problems/ipo/)

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
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        
        for(int i = 0; i < points.size(); ++i) {
            double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push({distance, i});
        }
        
        vector<vector<int>> res;
        while(k-- > 0 && !pq.empty()) {
            auto [dist, idx] = pq.top(); pq.pop();
            res.push_back(points[idx]);
        }
        
        return res;
    }
  ```
- [Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [Task Scheduler](https://leetcode.com/problems/task-scheduler/)
- [Design Twitter](https://leetcode.com/problems/design-twitter/)
- [Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array/)
- [Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/)
- [Single Threaded Cpu](https://leetcode.com/problems/single-threaded-cpu/)
- [Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/)
- [Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/)
- [Find The Kth Largest Integer In The Array](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/)
- [Reorganize String](https://leetcode.com/problems/reorganize-string/)
- [Longest Happy String](https://leetcode.com/problems/longest-happy-string/)
- [Car Pooling](https://leetcode.com/problems/car-pooling/)
- [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
- [Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team/)
- [IPO](https://leetcode.com/problems/ipo/)
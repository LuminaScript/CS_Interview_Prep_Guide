- [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) 🟠 MEDIUM 🔵 Greedy

  Time ```O(N)``` | Space ```O(1)```
  ```cpp
      int maxSubArray(vector<int>& nums) {
        int cur_res = nums[0];
        int max_res = cur_res;
        for(int i = 1; i < nums.size(); i++){
            int n = nums[i];
            cur_res = max(n, cur_res + n);
            max_res = max(max_res, cur_res);
        }
        return max_res;
    }
  ```
- [Jump Game](https://leetcode.com/problems/jump-game/) 🟠 MEDIUM 🔵 Greedy

  Time ```O(N)``` | Space ```O(1)```
  ```cpp
  bool canJump(vector<int>& nums) {
    int furtherestIndex = 0;
    for(int i = 0; i < nums.size(); i++){
        if(furtherestIndex >= i) furtherestIndex = max(furtherestIndex, i + nums[i]);
        if(furtherestIndex >= nums.size() - 1) return true;
    }
    return false;
  }
  ```
- [Jump Game II](https://leetcode.com/problems/jump-game-ii/) 🟠 MEDIUM 🔵 Greedy

  Time ```O(N)``` | Space ```O(1)```
  ```cpp
  int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    
    int curEnd = 0, furthestIdx = 0, jumps = 0;
    for(int i = 0; i < nums.size(); i++){
        if(furthestIdx >= i) furthestIdx = max(furthestIdx, i + nums[i]);
        if(i == curEnd){
            curEnd = furthestIdx;
            jumps++;
            if(furthestIdx >= nums.size() - 1) return jumps;
        }
    }
    return jumps;
  }
  ```
- [Gas Station](https://leetcode.com/problems/gas-station/)
- [Hand of Straights](https://leetcode.com/problems/hand-of-straights/)
  ```cpp
  bool isNStraightHand(vector<int>& hand, int W) {
    map<int, int> c;
    for (int i : hand) c[i]++;
    for (auto it : c)
        if (c[it.first] > 0)
            for (int i = W - 1; i >= 0; --i)
                if ((c[it.first + i] -= c[it.first]) < 0)
                    return false;
    return true;
  }
  ```
- [Merge Triplets to Form Target Triplet](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/)
- [Partition Labels](https://leetcode.com/problems/partition-labels/)
- [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

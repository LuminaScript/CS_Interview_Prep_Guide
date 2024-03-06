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
- [1899. Merge Triplets to Form Target Triplet](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/)

  O(N) + O(1)
  ```cpp
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
    vector<int> res(3);
    for(auto s : triplets){
        if(s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2])
            res = {max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2])};
    }
    return res == t;
  }
  ```
- [763. Partition Labels](https://leetcode.com/problems/partition-labels/)

  O(N) + O(1)
  ```cpp
  vector<int> partitionLabels(string s) {
    vector<int> last(26);
    for(int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
    int start = 0, end = 0;
    vector<int> res;
    for(int i = 0; i < s.size(); i++){
        end = max(end, last[s[i]- 'a']);
        if(end == i){
            res.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return res;
  }
  ```
- [678. Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)
  ```cpp
  bool checkValidString(string s) {
    int minleft = 0, maxleft = 0;
    for(auto c : s){
        if(c == '(') minleft++, maxleft++;
        else if(c == ')') minleft--, maxleft--;
        else minleft--, maxleft++;
        if(maxleft < 0) return false;
        minleft = max(0, minleft);
    }
    return minleft == 0;
  }
  ```

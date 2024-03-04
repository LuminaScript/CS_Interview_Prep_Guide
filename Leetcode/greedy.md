- [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) 🟠 MEDIUM 🔵 Greedy

  Time ```O(N)``` | Space ```O(N)```
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
- [Jump Game](https://leetcode.com/problems/jump-game/)
- [Jump Game II](https://leetcode.com/problems/jump-game-ii/)
- [Gas Station](https://leetcode.com/problems/gas-station/)
- [Hand of Straights](https://leetcode.com/problems/hand-of-straights/)
- [Merge Triplets to Form Target Triplet](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/)
- [Partition Labels](https://leetcode.com/problems/partition-labels/)
- [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

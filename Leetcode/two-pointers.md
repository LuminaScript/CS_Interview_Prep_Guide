# Two Pointers (2 Pointer) Techniques in LeetCode Problems

## Basic Knowledge

- **Common two-pointer algorithms** include same-direction, opposite-direction, and meeting-in-the-middle.
- **Same-direction pointers** move in the same direction.
- **Opposite-direction pointers** move toward each other.
- **Meeting-in-the-middle pointers** start from both ends and meet in the middle.

### Opposite-direction Pointers:

- [Leetcode 125. Valid Palindrome (I)](https://leetcode.com/problems/valid-palindrome/) **[EASY]**
  ```cpp
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while(l < r){
        while(l < r && !isalnum(s[l])) l++;
        while(l < r && !isalnum(s[r])) r--;
        if(tolower(s[l]) != tolower(s[r])) return false;
        l++, r--;
    }
    return true;
  }
  ```
- [Leetcode 125. Valid Palindrome (II)](https://leetcode.com/problems/valid-palindrome-ii/) **[EASY]**
  ```cpp
  bool helper(string s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
  }
  bool validPalindrome(string s) {
      int l = 0, r = s.size() - 1;
      while(l < r){
          if(s[l] != s[r]) return helper(s, l + 1, r) || helper(s, l, r - 1);
          l++, r--;
      }
      return true;
  }
  ```
- [Leetcode 1216. Valid Palindrome (III)](https://leetcode.com/problems/valid-palindrome-iii/) **[HARD]**
  ```cpp
  vector<vector<int>> memo;

  // Helper function to find the minimum deletions required to make the substring a palindrome
  int findMinDeletions(string &s, int l, int r) {
      if (l >= r) return 0;
      if (memo[l][r] != -1) return memo[l][r]; // Return cached result

      if (s[l] == s[r]) memo[l][r] = findMinDeletions(s, l + 1, r - 1);
      else memo[l][r] = 1 + min(findMinDeletions(s, l + 1, r), findMinDeletions(s, l, r - 1));
  
      return memo[l][r];
  }

  bool isValidPalindrome(string s, int k) {
      int n = s.length();
      memo.assign(n, vector<int>(n, -1));
      return findMinDeletions(s, 0, n - 1) <= k;
  }
  ```

- [Leetcode 2330. Valid Palindrome (IV)](https://leetcode.com/problems/valid-palindrome-iv/) **[MED]**
  ```cpp
  bool makePalindrome(string s) {
    int l = 0, r = s.size() - 1, cnt = 2;
    while(l < r){
        if(s[l] != s[r]){
            if(--cnt < 0) return false;
        }
        l++, r--;
    }
    return true; 
  }
  ```
- [Leetcode 5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
- [Leetcode 647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) **[MED]**
  ```cpp
  int countSubstrings(string s) {
    if(s.size() == 0 ) return 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        for(int l = i, r = i; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++)
            cnt ++;
        for(int l = i, r = i + 1; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++)
            cnt ++;
    }
    return cnt;
  }
  ```

### Meeting-in-the-middle Pointers:

- [Leetcode 1. Two Sum (using a two-pointer algorithm with sorting)](https://leetcode.com/problems/two-sum/) **[EASY]**
  
  **HashMap ```O(N)``` + ```O(N)```**
  ```cpp
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        if(mp.find(target - nums[i]) != mp.end()) return {mp[target - nums[i]], i};
        else mp[nums[i]] = i;
    }
    return {-1, -1};
  }
  ```
- [Leetcode 167. Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) **[MED]**

  **```O(N)``` + ```O(1)```**
  ```cpp
  vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l < r){
        int sum = nums[l] + nums[r];
        if(sum == target) return {l + 1, r + 1};
        if(sum > target) r--;
        else l++;
    }
    return {-1, -1};
  }
  ```
- [Leetcode 15. 3Sum](https://leetcode.com/problems/3sum/)
  
  **Two Pointers: Time -> ```O(N*2)``` + Space -> ```O(logN)``` ~ ```O(N)```, depends on sorting algo**
  ```cpp
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i <= nums.size() - 3 && nums[i] <= 0; i++){
        if(i > 0 && nums[i - 1] == nums[i]) continue;
        int j = i + 1, k = nums.size() - 1;
        int target = -nums[i];
        while(j < k){
            int sum = nums[j] + nums[k];
            if(sum > target) k--;
            else if(sum < target) j++;
            else{
                res.push_back({nums[i], nums[j++], nums[k--]});
                while(j < k && nums[j] == nums[j - 1]) j++;
            }
        }
    }
    return res;
  }
  ```
- [Leetcode 16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/)
- [Leetcode 18. 4Sum](https://leetcode.com/problems/4sum/)
- [Leetcode 454. 4Sum II](https://leetcode.com/problems/4sum-ii/)
- [Leetcode 277. Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/)
- [Leetcode 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
- [Leetcode 186 Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/)

### Same-direction Pointers:

- [Leetcode 283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [Leetcode 26. Remove Duplicate Numbers in Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
- [Leetcode 395. Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)
- [Leetcode 340. Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
- [Leetcode 424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
- [Leetcode 76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [Leetcode 3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [Leetcode 1004 Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)
- [Leetcode 1658 Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

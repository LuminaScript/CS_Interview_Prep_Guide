# Two Pointers (2 Pointer) Techniques in LeetCode Problems

## I.Opposite-direction Pointers:

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

## II. Meeting-in-the-middle Pointers:

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
- [Leetcode 15. 3Sum](https://leetcode.com/problems/3sum/) **[MED]**
  
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

  **No-Sort + HashMap: ```O(N*2)``` + ```O(N)```**
  ```cpp
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> res;
    unordered_set<int> dups;
    unordered_map<int, int> seen;
    for(int i = 0; i < nums.size(); i++){
        if (dups.insert(nums[i]).second) {
            for(int j = i + 1; j < nums.size(); j++){
                int comp = -nums[i] - nums[j];
                auto it = seen.find(comp);
                if(it != seen.end() && it->second == i){
                    vector<int> trip = {nums[i], nums[j], comp};
                    sort(trip.begin(), trip.end());
                    res.insert(trip);
                }
                seen[nums[j]] = i; // i has a match with j
            }
        }
    }
    return vector<vector<int>>(begin(res), end(res));
  }
  ```
- [Leetcode 16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/) **[MED]**

  **Time : ```O(NlogN)``` + ```O(N^2)``` = ```O(N^2)``` | Space : ```O(logN)``` ~ ```O(N)```, depends on sorting algo**
  
  ```cpp
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int dif = INT_MAX;
    int res = target;
    for(int i = 0; i < nums.size(); i++){
        int j = i + 1, k = nums.size() - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            dif = abs(target - sum) < abs(dif) ? target - sum : dif;
            if(dif == 0) return target - dif;
            if(sum > target) k--;
            else if(sum < target) j++;
        }
    }
    return target - dif;
  }
  ```
- [Leetcode 18. 4Sum](https://leetcode.com/problems/4sum/)
  
  **Time : ```O(N*3)``` | Space : ```O(logN)``` ~ ```O(N)```, depends on sorting algo**
  ```cpp
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for(int i = 0; i < n - 3; i++){
        if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicate i values
        for(int j = i + 1; j < n - 2; j++){
            if (j > i + 1 && nums[j] == nums[j-1]) continue;  // Skip duplicate j values
            long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
            int low = j + 1, high = n - 1;
            while(low < high){
                int sum = nums[low] + nums[high];
                if (sum < newTarget)
                    low++;
                else if (sum > newTarget)
                    high--;
                else {
                    res.push_back({nums[i], nums[j], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1]) low++; // Skip duplicate low values
                    while (low < high && nums[high] == nums[high - 1]) high--; // Skip duplicate high values
                    low++;
                    high--;
                }
            }
        }
    }
    return res;
  }
  ```
- [Leetcode 454. 4Sum II](https://leetcode.com/problems/4sum-ii/) **[MED]**

  **For 4 arrays:**
  ```cpp
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      int cnt = 0;
      unordered_map<int, int> m;
      for (int a : A) {
          for (int b : B) {
              ++m[a + b];
          }
      }
      
      for (int c : C) {
          for (int d : D) {
              auto it = m.find(-(c + d));
              if (it != end(m)) {
                  cnt += it->second;
              }
          }    
      }
      return cnt;
  }
  ```

  **For N arrays:**
  ```cpp
  // Function to compute sum counts for a list of vectors
  unordered_map<int, int> sumCount(vector<vector<int>>& lists) {
      unordered_map<int, int> res = {{0, 1}}; // Initialize with sum 0 having count 1
      for (auto& list : lists) {
          unordered_map<int, int> temp;
          for (int num : list) {
              for (auto& [total, count] : res) {
                  temp[total + num] += count;
              }
          }
          res = move(temp); // Move temp to res for the next iteration
      }
      return res;
  }

  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      // Split the original lists into two halves
      vector<vector<int>> firstHalf = {A, B};
      vector<vector<int>> secondHalf = {C, D};

      // Get sum counts for each half
      auto left = sumCount(firstHalf);
      auto right = sumCount(secondHalf);

      int result = 0;
      // Calculate the final count by multiplying complementary sum counts
      for (auto& [sum, count] : left) {
          if (right.find(-sum) != right.end()) {
              result += count * right[-sum];
          }
      }

      return result;
  }
  ```

- [Leetcode 277. Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/) **[MED]**

  **Time : ```O(N)``` + Space : ```O(1)```**
  ```cpp
  int findCelebrity(int n) {
    int celebrity_candidate = 0;
    for(int i = 0; i < n; i++){
        if(knows(celebrity_candidate, i))
            celebrity_candidate = i;
    }
    for(int j = 0; j < n; j++){
        if(j == celebrity_candidate) continue;
        if(knows(celebrity_candidate, j) || !knows(j, celebrity_candidate)) return -1;
    }
    return celebrity_candidate;
  }
  ```
- [Leetcode 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) **[MED]**

  **Time : ```O(N)``` + Space : ```O(1)```**
  ```cpp
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxArea = 0;
    while(l < r){
        int lHeight = height[l], rHeight = height[r];
        int curArea = (r - l) * min(lHeight, rHeight);
        maxArea = max(maxArea, curArea);
        if(lHeight < rHeight) l++;
        else r--;
    }
    return maxArea;
  }
  ```
- [Leetcode 186 Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/) **[MED]**

  **Time : ```O(N)``` + Space : ```O(1)```**
  ```cpp
  void swap(char* i, char* j){
    char temp = *i;
    *i = *j;
    *j = temp;
  }
  void reverseWords(vector<char>& s) {
      for(int l = 0, r = s.size() - 1; l < r; l++, r--) swap(&s[l], &s[r]);
  
      int i = 0;
      while(i < s.size()){
          int j = i;
          while(j < s.size() && s[j] != ' ') j++;
          for(int l = i, r = j - 1; l < r; l++, r--) swap(&s[l], &s[r]);
          i = j + 1;
      }
  }
  ```

## III. Same-direction Pointers:

- [Leetcode 283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [Leetcode 26. Remove Duplicate Numbers in Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
- [Leetcode 395. Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/) **[MED]**

  **Time : ```O(26 * N)``` = ```O(N)``` | Space : ```O(1)```**
  ```cpp
  int longestSubstring(string s, int k) {
      // Step 1: Calculate the total number of unique characters in the string.
      unordered_set<char> uniqueCharsSet(s.begin(), s.end());
      int totalUnique = uniqueCharsSet.size();

      int maxLen = 0;
      
      // Step 2: Apply sliding window technique for each possible number of unique target characters.
      for (int uniqueTarget = 1; uniqueTarget <= totalUnique; ++uniqueTarget) {
          vector<int> freq(26, 0);
          int start = 0, end = 0;
          int uniqueChars = 0, charsAtLeastK = 0;
          while (end < s.length()) {
              if (uniqueChars <= uniqueTarget) {
                  int index = s[end] - 'a';
                  if (freq[index]++ == 0) uniqueChars++;
                  if (freq[index] == k) charsAtLeastK++;
                  end++;
              } else {
                  int index = s[start] - 'a';
                  if (freq[index]-- == k) charsAtLeastK--;
                  if (freq[index] == 0) uniqueChars--;
                  start++;
              }
              
              if (uniqueChars == uniqueTarget && uniqueChars == charsAtLeastK) {
                  maxLen = max(maxLen, end - start);
              }
          }
      }
      
      return maxLen;
  }
  ```
- [Leetcode 340. Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) **[MED]**

  **Time : ```O(N)``` * ```O(N - 1)``` = ```O(N)``` | Space : ```O(1)```**
  ```cpp
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> cnt;
    int start = 0, end = 0, maxLen = 0;
    while(end < s.size()){
        char endc = s[end];
        if(cnt.find(endc) == cnt.end()) cnt[endc] = 1;
        else cnt[endc]++;

        while(cnt.size() > k){
            if(--cnt[s[start]] == 0) cnt.erase(s[start]);
            start++;
        }
        maxLen = std::max(maxLen, end - start + 1);
        end++;
    }
    return maxLen;
  }
  ```
- [Leetcode 424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)

  **Time : ```O(N)``` | Space : ```O(1)```**
  ```cpp
  int characterReplacement(string s, int k) {
    vector<int> freqMap(26, 0);
    int start = 0, maxFreq = 0, maxLen = 0;
    for(int end = 0; end < s.size(); end++){
        int curChar = s[end] - 'A';
        maxFreq = max(maxFreq, ++freqMap[curChar]);
        bool isValid = (end - start + 1 - maxFreq <= k);
        if(!isValid){
            int removeChar = s[start] - 'A';
            freqMap[removeChar]--;
            start++;
        }
        maxLen = end + 1 - start;
    }
    return maxLen;
  }
  ```
- [Leetcode 76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

  **Time : ```O(N)``` | Space : ```O(1)```**
  ```cpp
  string minWindow(string s, string t) {
    vector<int> t_map(128, 0);
    for (char c : t) t_map[c]++;
    
    int left = 0, right = 0;
    int min_len = INT_MAX, min_start = 0, found_chars = 0;
    while (right < s.size()) {
        if (t_map[s[right]] > 0) found_chars++;
        t_map[s[right]]--;

        while (found_chars == t.size()) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_start = left;
            }
            if (t_map[s[left]] == 0)found_chars--;
            t_map[s[left++]]++;
        }
        right++;
    }

    return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
  }
  ```
- [Leetcode 3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

  **Time : ```O(N)``` | Space : ```O(1)```**
  ```cpp
  int lengthOfLongestSubstring(string s) {
    vector<bool> seen(128, false);
    int start = 0, maxLen = 0;
    for(int end = 0; end < s.size(); end++){
        if(seen[s[end]] == false) seen[s[end]] = true;
        else{
            while(s[end] != s[start]) seen[s[start++]] = false;
            start++;
        }
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
  }
  ```
- [Leetcode 1004 Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)

   **Time : ```O(N)``` | Space : ```O(1)```**
  ```cpp
  int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0, left = 0;
    for(int right = 0; right < nums.size(); right++){
        if(nums[right] == 0){
            if(--k < 0){
                while(nums[left] != 0) left++;
                left++;
                k++;
            }
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
  ```
- [Leetcode 1658 Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/) **[MED]** **
  ```cpp
  int minOperations(vector<int>& nums, int x) {
    int cur = 0, n = nums.size(), mini = INT_MAX, left = 0;
    for(int n : nums) cur += n;

    for(int right = 0; right < n; right++){
        cur -= nums[right];
        while(cur < x && left <= right) cur += nums[left++];
        if(cur == x) mini = min(mini, (n - 1 - right) + left);
    }
    return mini != INT_MAX ? mini : -1;
  }
  ```

- [121. Best Time to Buy And Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) 🟢 EASY 🔵 Sliding Windows
  ```cpp
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    for(int r = 0, l = 0; r < prices.size(); r++){
        if(prices[r] > prices[l]) maxProfit = max(maxProfit, prices[r] - prices[l]);
        else l = r;
    }
    return maxProfit;
  }
  ```
- [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) 🟢 EASY 🔵 Sliding Windows 🔵 Hash Map
  ```cpp
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        if(mp.count(nums[i]) && i - mp[nums[i]] <= k) return true;
        mp[nums[i]] = i;
    }
    return false;
  }
  ```
- [1314. Number of Subarrays of Size K and Avg Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/) 🟠 MEDIUM 🔵 Sliding Windows
  ```cpp
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int curSum = 0, res = 0;
    for(int i = 0; i < arr.size(); i++){
        curSum += arr[i];
        if(i < k - 1) continue;
        if(i - k >= 0) curSum -= arr[i - k];
        if(curSum / k >= threshold) res++;
    }
    return res;
  }
  ```
- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) 🟠 MEDIUM 🔵 Sliding Windows 🔵 Hash Map
  ```cpp
  int lengthOfLongestSubstring(string s) {
    unordered_map<int, int> mp;
    int maxLen = 0;
    for(int l = 0, r = 0; r < s.size(); r++){
        if(mp.find(s[r]) != mp.end()){
            while(l <= mp[s[r]]) mp.erase(s[l++]);
        } 
        mp[s[r]] = r;
        maxLen = std::max(maxLen, r - l + 1);
    }
    return maxLen; 
  }
  ```
- [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement)
- [567. Permutation in String](https://leetcode.com/problems/permutation-in-string) 🟠 MEDIUM 🔵 Sliding Windows 🔵 Hash Map

  **Time ```O(sn)``` + Space ```O(1)```**
  ```cpp
  bool checkInclusion(string p, string s) {
    int pn = p.size(), sn = s.size();
    if(sn < pn) return false;
    vector<int> ref(26, 0);
    vector<int> windows(26, 0);
    for(char c : p) ref[c - 'a']++;

    for(int i = 0; i < sn; i++){
        windows[s[i] - 'a']++;
        if(i >= pn) windows[s[i - pn] - 'a']--;
        if(ref == windows) return true;
    }
    return false;
  }
  ```
- [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element) 🟠 MEDIUM 🔵 Sliding Windows
  > We only care about the length of sliding windows, but not the content inside it.
  >
  > Does not shrink the windows, only expand it when we encounter longer valid windows.
  
  **Time ```O(NlogN)``` + Space ```O(N)```**
  ```cpp
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0;
    long curr = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        long target = nums[right];
        curr += target;
        
        if ((right - left + 1) * target - curr > k) {
            curr -= nums[left];
            left++;
        }
    }
    
    return nums.size() - left;
  }
  ```
- [904. Fruits into Baskets](https://leetcode.com/problems/fruit-into-baskets) 🟠 MEDIUM 🔵 Sliding Windows 🔵 Hash Map
  
  **Solution 1: Adjust Sliding Window's Size**
  ```cpp
  int totalFruit(vector<int>& fruits) {
      unordered_map<int, int> mp;
      int cnt = 0;
      int maxFruit = 0, curFruit = 0;
      for(int l = 0, r = 0; r < fruits.size(); r++){
          if(mp.find(fruits[r]) == mp.end()) cnt++;
          mp[fruits[r]]++;

          curFruit++;
          while(cnt > 2){
              if(--mp[fruits[l]] == 0){
                  mp.erase(fruits[l]);
                  cnt--;
              }
              l++;
              curFruit--;
          }
          maxFruit = std::max(curFruit, maxFruit);
      }
      return maxFruit;
  }
  ```

  **Solution 2: Never Shrinking Sliding Window** 🌟
  ```cpp
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
    int cnt = 0;
    int l = 0, r = 0;
    while(r < fruits.size()){
        if(mp.find(fruits[r]) == mp.end()) cnt++;
        mp[fruits[r]]++;
        if(mp.size() > 2){
            if(--mp[fruits[l]] == 0) mp.erase(fruits[l]);
            l++;
        }
        r++;
    }
    return r - l;
  }
  ```
- [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length) 🟠 MEDIUM 🔵 Sliding Windows

  **Time ```O(N)``` + Space ```O(1)```**
  ```cpp
  int maxVowels(string s, int k) {
    int maxVowel = 0, curVowel = 0;
    set<char> vowels= {'a', 'e', 'i', 'o', 'u'};
    for(int l = 0, r = 0; r < s.size(); r++){
        if(vowels.find(s[r]) != vowels.end()) curVowel++;
        if(r - l + 1 > k){
            if(vowels.find(s[l]) != vowels.end()) curVowel--;
            l++;
        }
        maxVowel = max(maxVowel, curVowel);
    }
    return maxVowel;
  }
  ```
- [Minimum Number of Flips to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating)
- [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum)
- [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements)
- [Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum)

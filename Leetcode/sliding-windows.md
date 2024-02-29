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
- [Permutation in String](https://leetcode.com/problems/permutation-in-string)
- [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element)
- [Fruits into Baskets](https://leetcode.com/problems/fruit-into-baskets) *(Note: The correct LeetCode problem title is "Fruit Into Baskets")*
- [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length)
- [Minimum Number of Flips to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating)
- [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum)
- [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements)
- [Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum)
